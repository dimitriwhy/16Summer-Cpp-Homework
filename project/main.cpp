#include <bits/stdc++.h>
using namespace std;
#include "Management.hpp"
#include "Convert.hpp"
int main(){
	char path[] = "doc.data";
		
	Management document;
	document.createFileSet(path,3);

	char path1[] = "a.txt";
	document.addFileToFileSet(path1);
	char path11[] = "aa.txt";
	cout << document.fetchFileFromFileSet(path1,path11) << endl;
	//document.deleteFileFromFileSet(path1);

	char path2[] = "b.txt";
	document.addFileToFileSet(path2);
	char path22[] = "bb.txt";
	cout << document.fetchFileFromFileSet(path2,path22) << endl;
	document.deleteFileFromFileSet(path2);

	char path3[] = "c.txt";
	document.addFileToFileSet(path3);
	char path33[] = "cc.txt";
	cout << document.fetchFileFromFileSet(path3,path33) << endl;

	char path4[] = "d.txt";
	document.addFileToFileSet(path4);
	char path44[] = "dd.txt";
	cout << document.fetchFileFromFileSet(path4,path44) << endl;

	document.closeFileSet();
	
	Management ndoc;
	ndoc.openFileSet(path);
	char path111[] = "aaa.txt";
	char path333[] = "ccc.txt";
	char path444[] = "ddd.txt";
	cout << ndoc.fetchFileFromFileSet(path1,path111) << endl;
	cout << ndoc.fetchFileFromFileSet(path3,path333) << endl;
	cout << ndoc.fetchFileFromFileSet(path4,path444) << endl;

	ndoc.printFileListInFileSet();
	return 0;
}
