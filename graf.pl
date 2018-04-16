% This buffer is for notes you don't want to save.
% If you want to create a file, visit that file with C-x C-f,
% then enter the text in that file's own buffer.

:-dynamic(node/1).
node(a).
node(b).
node(c).
node(d).


:- dynamic(edge/3).
edge(a,b,4).
edge(a,c,9).
edge(b,c,7).
edge(b,d,8).
edge(d,c,10).

meniu :- write("\nAlegeti optiunea:\n\t"),
	write("1.Adauga nod.\n\t"),
	write("2.Sterge nod.\n\t"),
	write("3.Adauga latura.\n\t"),
	write("4.Sterge latura.\n\t"),
	write("5.Printeaza graful.\n\t"),
	write("6.Cel mai scurt drum.\n\n\n\t"),
	write("9.Iesire.\n"),
	read(X),meniu(X).

meniu(1) :- write("Introduceti nodul care va fi adaugat.\n"),
	read(X),
	assert(node(X)),
	meniu.

meniu(2) :- write("Introduceti nodul care va fi sters.\n"),
	read(X),
	retract(node(X)),
	meniu.

meniu(3) :- write("Introduceti nodul 1.\n"),
	read(X),
	write("Introduceti nodul 2.\n"),
	read(Y),
	write("Introduceti distanta."),
	read(Z),
	assert(edge(X,Y,Z)),
	meniu.

meniu(4) :- write("Introduceti nodul 1.\n"),
	read(X),
	write("Introduceti nodul 2.\n"),
	read(Y),
	retract(edge(X,Y,_)),
	meniu.

meniu(5) :- findall([X,Y,Z],edge(X,Y,Z),Result),
	write(Result),
	write("\n"),
	meniu.

meniu(9) :- !.


