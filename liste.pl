inserting(Item,[],[Item]).
inserting(Item,[H|List],[H|Res]) :- inserting(Item,List,Res).

deleting-one(Item,[Item|Tail],Tail).
deleting-one(Item,[Head|Tail],[Head|Res]) :-
	deleting-one(Item,Tail,Res).

deleting-all(Item,[Item],[]) :- !.
deleting-all(Item,[Item|Tail],Res):-
	deleting-all(Item,Tail,Res),!.
deleting-all(Item,[Head|Tail],[Head|Res]) :-
	deleting-all(Item,Tail,Res).


rotate-one([Head],Acc,[Head|Acc]).
rotate-one([Head|Tail],Acc,Res) :-
	Head is Head+0,
	append([Acc],Tail,Res),
	rotate-one(Tail,Acc,Res).


range(Min,Min,[Min]).
range(Min,Max,Res):-
	Max>=Min,
	Max is Max-1,
	Aux is Res,
	append([Min],Aux,Res),
	range(Min,Max,Res).

duplicate([],[]).
duplicate([Head|Tail],[[Head,Head]|Res]) :- duplicate(Tail,Res).



