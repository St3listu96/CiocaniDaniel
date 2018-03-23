% This buffer is for notes you don't want to save.
% If you want to create a file, visit that file with C-x C-f,
% then enter the text in that file's own buffer.

add(null,0).

add(tree(Root,null,null),Root) :- !.
add(tree(Root,Stanga,Dreapta),S) :-
	add(Stanga,S1),
	add(Dreapta,D1),
	S is Root+S1+D1.

count_leaves(null,0).
count_leaves(tree(_,null,null),1) :- !.
count_leaves(tree(_,Stanga,Dreapta),Count) :-
	count_leaves(Stanga,C1),
	count_leaves(Dreapta,C2),
	Count is C1+C2.

compute(tree(Root,null,null),Root).
compute(tree(+,Stanga,Dreapta),Result):-
	compute(Stanga,R1),
	compute(Dreapta,R2),
	Result is R1+R2.

compute(tree(-,Stanga,Dreapta),Result):-
	compute(Stanga,R1),
	compute(Dreapta,R2),
	Result is R1-R2.

compute(tree(*,Stanga,Dreapta),Result):-
	compute(Stanga,R1),
	compute(Dreapta,R2),
	Result is R1*R2.

compute(tree(/,Stanga,Dreapta),Result):-
	compute(Stanga,R1),
	compute(Dreapta,R2),
	Result is R1/R2.

converting(X,tree(X,null,null)) :- number(X).
converting(E1+E2,tree(+,R1,R2)) :-
	converting(E1,R1),
	converting(E2,R2).

converting(E1-E2,tree(-,R1,R2)) :-
	converting(E1,R1),
	converting(E2,R2).


converting(E1*E2,tree(*,R1,R2)) :-
	converting(E1,R1),
	converting(E2,R2).

converting(E1/E2,tree(/,R1,R2)) :-
	converting(E1,R1),
	converting(E2,R2).


