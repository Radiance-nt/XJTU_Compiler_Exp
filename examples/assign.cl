class Main inherits IO{
	x:Int;
	main () : Object {
		while x<9000 loop out_int (x<-x+1) pool
	};
};
