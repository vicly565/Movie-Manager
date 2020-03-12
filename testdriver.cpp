#pragma once
#include <iostream>;
#include "movie.h";
#include "classic.h"
#include "comedy.h"
#include "drama.h";
#include "bintree.h";

using namespace std;

int main() {
	//classic testing
	Classic test1('C', 10, "Michael Curtiz", "Casablanca", "Ingrid Bergman", 8, 1942);
	Classic test2('C', 10, "Michael Curtiz", "Casablanca", "Humphrey Bogart", 8, 1942);
	Classic test3('C', 10, "Hal Ashby", "Harold and Maude", "Ruth Gordon", 3, 1971);
	Classic test4('C', 10, "George Cukor", "Holiday", "Katherine Hepburn", 9, 1938);
	Classic test5('C', 10, "George Cukor", "Holiday", "Cary Grant", 9, 1938);
	Classic test6('C', 10, "Victor Fleming", "Gone With the Wind", "Vivien Leigh", 2, 1939);
	Classic test7('C', 10, "Victor Fleming", "Gone With the Wind", "Clark Gable", 2, 1939);
	Classic test8('C', 10, "George Cukor", "The Philadelphia Story", "Katherine Hepburn", 5, 1940);
	Classic test9('C', 10, "George Cukor", "The Philadelphia Story", "Cary Grant", 5, 1940);
	Classic test10('C', 10, "Michael Curtiz", "Casablanca", "Ingrid Bergman", 8, 1942);
	test1.display();
	test2.display();
	test3.display();
	test4.display();
	test5.display();
	test6.display();
	test7.display();
	test8.display();
	test9.display();
	cout << (test1 > test2);
	cout << (test1 < test2);
	cout << (test1 > test5);
	cout << (test5 > test9);
	cout << (test1 == test10);
	cout << (test1 == test2);
	cout << endl;

	Comedy test11('F', 10, "Nora Ephron", "Sleepless in Seattle", 1993);
	Comedy test12('F', 10, "Woody Allen", "Annie Hall", 1977);
	Comedy test13('F', 10, "Rob Reiner", "When Harry Met Sally", 1989);
	Comedy test14('F', 10, "Gore Verbinski", "Pirates of the Caribbean", 2003);
	Comedy test15('F', 10, "Joel Coen", "Fargo", 1996);
	Comedy test16('F', 10, "John Landis", "National Lampoon's Animal House", 1978);
	Comedy test17('F', 10, "Nora Ephron", "You've Got Mail", 1998);
	Comedy test18('F', 10, "Nora Ephron", "Sleepless in Seattle", 1993);
	test11.display();
	test12.display();
	test13.display();
	test14.display();
	test15.display();
	test16.display();
	test17.display();
	cout << (test11 > test12);
	cout << (test11 < test12);
	cout << (test11 > test15);
	cout << (test15 > test14);
	cout << (test11 == test18);
	cout << (test11 == test12);
	cout << endl;


	Drama test21('D', 10, "Barry Levinson", "Good Morning Vietnam", 1988);
	Drama test22('D', 10, "Gus Van Sant", "Good Will Hunting", 2000);
	Drama test23('D', 10, "Phillippe De Broca", "King of Hearts", 1967);
	Drama test24('D', 10, "Steven Spielberg", "Schindler's List", 1993);
	Drama test25('D', 10, "Jonathan Demme", "Silence of the Lambs", 1991);
	Drama test26('D', 10, "Nancy Savoca", "Dogfight", 1991);
	Drama test27('D', 10, "Barry Levinson", "Good Morning Vietnam", 1988);
	test21.display();
	test22.display();
	test23.display();
	test24.display();
	test25.display();
	test26.display();
	cout << (test21 > test22);
	cout << (test21 < test22);
	cout << (test21 > test25);
	cout << (test25 > test24);
	cout << (test21 == test27);
	cout << (test21 == test22);
	cout << endl;

	BinTree Classi;
	Classi.insert(&test1);
	Classi.insert(&test2);
	Classi.insert(&test3);
	Classi.insert(&test4);
	Classi.insert(&test5);
	Classi.insert(&test6);
	Classi.insert(&test7);
	Classi.insert(&test8);
	Classi.insert(&test9);
	Classi.insert(&test10);
	Classi.display();
}