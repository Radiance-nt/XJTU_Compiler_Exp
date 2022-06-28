(*
	Author：武万杰
	Date：2013/3/10
	这是个demo程序，主要作用是完成作业中的第一个任务，目的给大家演示如何使用
	Cool语言，运行的方法。
*)

(*
	CoAuthor：rad
	Date：2022/6/28
	Split demo.cl intto stack.cl and utils.cl to meet Dai's demand.
*)

(*
   The class A2I provides integer-to-string and string-to-integer
conversion routines.  To use these routines, either inherit them
in the class where needed, have a dummy variable bound to
something of type A2I, or simpl write (new A2I).method(argument).
*)


(*
   c2i   Converts a 1-character string to an integer.  Aborts
         if the string is not "0" through "9"
*)

class List inherits IO
{
	isNil() : Bool 
	{
		{
			--out_string("list\n");
			true;
		}
	};
	
	head() : String
	{
		{
			abort();
			"";
		}
	};
	
	tail() : List
	{
		{
			abort();
			self;
		}
	};
	cons(i : String) : List
	{
		(new Cons).init(i, self)
	};
};

class Cons inherits List
{
	first : String;
	rest :  List;
	isNil() : Bool
	{
		{
			false;
		}
	};
	head() : String
	{	
		first
	};
	tail() : List
	{
		rest
	};
	init(head : String, next : List) : List
	{
		{
			first <- head;
			rest  <- next;
			self;
		}
	};
};


class Main inherits IO
{
	stack : List;
	
	newline() : Object
	{
		out_string("\n")
	};
	
	prompt() : String
	{
		{
			out_string(">");
			in_string();
		}
	};
	
	display_stack(s : List) : Object
	{
		{
			if s.isNil() then 
            out_string("")
         else
         {
            out_string(s.head());
            out_string("\n");
            display_stack(s.tail());
         }
		fi;
		}
	};
	
	main():Object
	{
		( let z : A2I <- new A2I  , stack : List <- new List in
			while true loop
			( let s : String <- prompt() in
				if s = "x" then
					abort()
				else
					if s = "d"  then
						display_stack(stack)
					else
					    if s = "e"  then
							{
								if stack.isNil() then out_string("")
								
								else
								if stack.head() = "+" then
									{
										stack <- stack.tail();
										(let a : Int <- new Int, b : Int <- new Int in 	
											{
												--out_string(stack.head());
												a  <- z.a2i(stack.head());
												stack <- stack.tail();
												b  <- z.a2i(stack.head());
												stack <- stack.tail();
												a <- a + b;
												--out_string(z.i2a(a));
												stack <- stack.cons(z.i2a(a));
											}
										);
									}
								else
									if stack.head() = "s" then
										{
											stack <- stack.tail();
											(let a : String <- new String , b : String <- new String in 
												{
													a  <- stack.head();
													stack <- stack.tail();
													b  <- stack.head();
													stack <- stack.tail();
													stack <- stack.cons(a);
													stack <- stack.cons(b);
												}
											);
										}
									else
										out_string("")
									fi
									fi
								fi;
							}
						else
							stack <- stack.cons(s)
						fi
					fi
				fi
			)
			pool
		)
	};
};
	
