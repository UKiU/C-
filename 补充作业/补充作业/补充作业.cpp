#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<fstream>
#include<cstdio>
using namespace std;

int main()
{   
    unsigned short* p = new unsigned short[82 * 82 * 78];
    FILE* ifile=fopen("D:\\app\\QQ\\xiaoxijilu\\1181160526\\FileRecv\\第四章补充作业\\3DImage.raw","rb");
    FILE* ofile=fopen("D:\\app\\QQ\\xiaoxijilu\\1181160526\\FileRecv\\第四章补充作业\\3DImageX40.raw","wb");
    if (!ifile) {
        cout << "False" << endl;
    }
    else {
        fread(p, sizeof(unsigned short), 82 * 82 * 78, ifile);
        fwrite(&p[39 * 82], sizeof(unsigned short), 82 * 72, ofile);
    }
    fclose(ifile);
    fclose(ofile);
    delete[]p;
    return 0;
}

