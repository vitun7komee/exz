// Вильчак ким 2
#include <iostream>
#include <fstream>
#include <string>
#include "Forward_List.h"
#include "Double_List.h"
#include "Binary_Tree.h"

auto y = [](int x) {
	while (x > 10) { x /= 3; }
	if (x % 3 == 0) {
		return true;
	}
	else return false;
};
void task1(FLIST& list) {
	ptrNODEL p = list.get_head();
	ptrNODEL first = nullptr;
	ptrNODEL last = nullptr;
	bool flag = true;
	while (p->next && flag) {
		if (y(p->next->info)) {
			first = p;
			flag = false;
		}
		p = p->next;
	}
	while (p->next) {

		if (y(p->next->info)) {

			last = p;

		}
		//if (!flag) { first = p; }
		p = p->next;
	}
	if (last && first) {
		
		while (first->next != last ) { list.delete_by_pointer(first->next); }
	}
}
void task2(DLIST& list) {
	ptrNODEDL p = list.get_begin();
	ptrNODEDL onex = p;
	ptrNODEDL twox = nullptr;
	double sum = 0;
	int counter = 1;
	while (p->next) {
		sum += p->info;
		counter++;
		if (counter % 2 == 0) { onex = onex->next;  }
		p = p->next;
	}
	std::cout << std::endl << counter << " ";
	if (counter % 2 == 0) { list.add_after(onex, sum); }

}
//double task4(NODEBT root, int lvl) {
//	int i = 0; int sum = 0;
//	std::stack<NODEBT> myStack;
//	mtStack.push(root);
//	bool flag ;
//	while (!myStack.empty() && i <= lvl) {
//		flag = false;
//		NODEBT current = myStack.top();
//		myStack.pop();
//		sum += current.info();
//		if (current.left && i < lvl) {
//			flag = true;
//			myStack.push(current.left);
//
//		}
//		if (current.right && i < lvl) {
//			flag = true;
//			myStack.push(current.right);
//		}
//	}
//	if (flag) { i++; }
//	return sum;
//}
int main() {
	setlocale(0, "");
	/*std::ifstream("data_tree.txt");
	NODEBT root 
	t*/
	
	std::ifstream file("data_list.txt");
	FLIST list("data_list.txt");
	list.print();
	task1(list);
	list.print();
	std::ifstream file1("data_list.txt");
	DLIST list1("data_list.txt");
	list1.print();
	task2(list1);
	list1.print();

}