#include "Person.h"
#include "MyList.h"
#include "Ordinary.h"
#include "Professor.h"
#include "Student.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <locale>
#include "Manager.h"

using namespace std;

int main(int argc, char* argv[]) {
	cout << "***************** 발전기금 관리 프로그램 *****************" <<endl;
	Manager* m = new Manager();
	m->loadFile(argv);
	m->menu();
	m->saveFile(argv);
	return 0;

}
