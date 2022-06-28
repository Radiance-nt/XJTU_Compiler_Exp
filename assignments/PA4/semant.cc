

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include "semant.h"
#include "utilities.h"


extern int semant_debug;
extern char *curr_filename;

//////////////////////////////////////////////////////////////////////
//
// Symbols
//
// For convenience, a large number of symbols are predefined here.
// These symbols include the primitive type and method names, as well
// as fixed names used by the runtime system.
//
//////////////////////////////////////////////////////////////////////
static Symbol 
    arg,
    arg2,
    Bool,
    concat,
    cool_abort,
    copy,
    Int,
    in_int,
    in_string,
    IO,
    length,
    Main,
    main_meth,
    No_class,
    No_type,
    Object,
    out_int,
    out_string,
    prim_slot,
    self,
    SELF_TYPE,
    Str,
    str_field,
    substr,
    type_name,
    val;
//
// Initializing the predefined symbols.
//
static void initialize_constants(void)
{
    arg         = idtable.add_string("arg");
    arg2        = idtable.add_string("arg2");
    Bool        = idtable.add_string("Bool");
    concat      = idtable.add_string("concat");
    cool_abort  = idtable.add_string("abort");
    copy        = idtable.add_string("copy");
    Int         = idtable.add_string("Int");
    in_int      = idtable.add_string("in_int");
    in_string   = idtable.add_string("in_string");
    IO          = idtable.add_string("IO");
    length      = idtable.add_string("length");
    Main        = idtable.add_string("Main");
    main_meth   = idtable.add_string("main");
    //   _no_class is a symbol that can't be the name of any 
    //   user-defined class.
    No_class    = idtable.add_string("_no_class");
    No_type     = idtable.add_string("_no_type");
    Object      = idtable.add_string("Object");
    out_int     = idtable.add_string("out_int");
    out_string  = idtable.add_string("out_string");
    prim_slot   = idtable.add_string("_prim_slot");
    self        = idtable.add_string("self");
    SELF_TYPE   = idtable.add_string("SELF_TYPE");
    Str         = idtable.add_string("String");
    str_field   = idtable.add_string("_str_field");
    substr      = idtable.add_string("substr");
    type_name   = idtable.add_string("type_name");
    val         = idtable.add_string("_val");
}

static Class_ curr_class = 0;


static int semant_errors = 0;
static std::ostream& error_stream = std::cerr;

static std::ostream& semant_error() {
    semant_errors++;
    return error_stream;
}

static std::ostream& semant_error(tree_node *t) {
    error_stream << curr_class->getFileName() << ":" << t->get_line_number() << ": ";
    return semant_error();
}

static std::ostream& internal_error(int lineno) {
    error_stream << "FATAL:" << lineno << ": ";
    return error_stream;
}

static void install_basic_classes(void) {
    // The tree package uses these globals to annotate the classes built below.
    // curr_lineno  = 0;
    Symbol filename = stringtable.add_string("<basic class>");
    
    // 
    // The Object class has no parent class. Its methods are
    //        abort() : Object    aborts the program
    //        type_name() : Str   returns a string representation of class name
    //        copy() : SELF_TYPE  returns a copy of the object
    //
    // There is no need for method bodies in the basic classes---these
    // are already built in to the runtime system.

    Class_ Object_class =
	class_(Object, 
	       No_class,
	       append_Features(
			       append_Features(
					       single_Features(method(cool_abort, nil_Formals(), Object, no_expr())),
					       single_Features(method(type_name, nil_Formals(), Str, no_expr()))),
			       single_Features(method(copy, nil_Formals(), SELF_TYPE, no_expr()))),
	       filename);

    // 
    // The IO class inherits from Object. Its methods are
    //        out_string(Str) : SELF_TYPE       writes a string to the output
    //        out_int(Int) : SELF_TYPE            "    an int    "  "     "
    //        in_string() : Str                 reads a string from the input
    //        in_int() : Int                      "   an int     "  "     "
    //
    Class_ IO_class = 
	class_(IO, 
	       Object,
	       append_Features(
			       append_Features(
					       append_Features(
							       single_Features(method(out_string, single_Formals(formal(arg, Str)),
										      SELF_TYPE, no_expr())),
							       single_Features(method(out_int, single_Formals(formal(arg, Int)),
										      SELF_TYPE, no_expr()))),
					       single_Features(method(in_string, nil_Formals(), Str, no_expr()))),
			       single_Features(method(in_int, nil_Formals(), Int, no_expr()))),
	       filename);  

    //
    // The Int class has no methods and only a single attribute, the
    // "val" for the integer. 
    //
    Class_ Int_class =
	class_(Int, 
	       Object,
	       single_Features(attr(val, prim_slot, no_expr())),
	       filename);

    //
    // Bool also has only the "val" slot.
    //
    Class_ Bool_class =
	class_(Bool, Object, single_Features(attr(val, prim_slot, no_expr())),filename);

    //
    // The class Str has a number of slots and operations:
    //       val                                  the length of the string
    //       str_field                            the string itself
    //       length() : Int                       returns length of the string
    //       concat(arg: Str) : Str               performs string concatenation
    //       substr(arg: Int, arg2: Int): Str     substring selection
    //       
    Class_ Str_class =
	class_(Str, 
	       Object,
	       append_Features(
			       append_Features(
					       append_Features(
							       append_Features(
									       single_Features(attr(val, Int, no_expr())),
									       single_Features(attr(str_field, prim_slot, no_expr()))),
							       single_Features(method(length, nil_Formals(), Int, no_expr()))),
					       single_Features(method(concat, 
								      single_Formals(formal(arg, Str)),
								      Str, 
								      no_expr()))),
			       single_Features(method(substr, 
						      append_Formals(single_Formals(formal(arg, Int)), 
								     single_Formals(formal(arg2, Int))),
						      Str, 
						      no_expr()))),
	       filename);

    classTable[Object_class->getName()] = Object_class;
    classTable[IO_class->getName()] = IO_class;
    classTable[Int_class->getName()] = Int_class;
    classTable[Bool_class->getName()] = Bool_class;
    classTable[Str_class->getName()] = Str_class;
}

static void install_classes(Classes classes) {
    for (int i = classes->first(); classes->more(i); i = classes->next(i)) {
        curr_class = classes->nth(i);
        Symbol pname = curr_class->getParentName();
        if (curr_class->getName() == SELF_TYPE)
            semant_error(curr_class) << "Redefinition of basic class SELF_TYPE.\n";
        else if (classTable.find(curr_class->getName()) != classTable.end())
            semant_error(curr_class) << "Class " << curr_class->getName() << " was previously defined.\n";
        else if (pname == Int || pname == Str || pname == Bool || pname == SELF_TYPE)
            semant_error(curr_class) << "Class " << curr_class->getName() << " cannot inherit class " << pname << ".\n";
        else
            classTable[curr_class->getName()] = curr_class;
    }
}
static void check_inheritance() {
    for (ClassTable::iterator it = classTable.begin(); it != classTable.end(); it++)
        if (it->first != Object && classTable.find(it->second->getParentName()) == classTable.end()) {
            curr_class = it->second;
            semant_error(curr_class) << "Class " << it->second->getName() << " inherits from an undefined class " << it->second->getParentName() << ".\n";
        }
    
    for (ClassTable::iterator it = classTable.begin(); it != classTable.end(); it++) {
        if (it->first == Object) continue;
        curr_class = it->second;
        Symbol cname = it->first;
        Symbol pname = it->second->getParentName();
        while (pname != Object) {
            if (pname == cname) {
                semant_error(curr_class) << "Class " << curr_class->getName() << ", or an ancestor of " << curr_class->getName() << ", is involved in an inheritance cycle.\n";
                break;
            }
            if (classTable.find(pname) == classTable.end())
                break;
            pname = classTable[pname]->getParentName();
        }
    }
}

/*   This is the entry point to the semantic checker.

     Your checker should do the following two things:

     1) Check that the program is semantically correct
     2) Decorate the abstract syntax tree with type information
        by setting the `type' field in each Expression node.
        (see `tree.h')

     You are free to first do 1), make sure you catch all semantic
     errors. Part 2) can be done in a second stage, when you want
     to build mycoolc.
 */
void program_class::semant()
{
    initialize_constants();
    install_basic_classes();
    install_classes(classes);
    check_inheritance();

    if (semant_errors > 0) {
        std::cerr << "Compilation halted due to static semantic errors." << std::endl;
        exit(1);
    }
}


