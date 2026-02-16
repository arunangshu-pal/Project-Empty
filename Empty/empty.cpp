/*
Program to empty text files.
When the program is run with a list of text files as command-line arguments, the files will be emptied, i.e. the contents of the files will be deleted (and the files themselves are not deleted). The usage syntax given below clarifies how the program works. Confirmation is taken from the user for each empty operation (default behaviour); only a response of "yes" will cause a file to be emptied.

Syntax:
$ <executabl> [OPTION] [FILE]
[FILE] is a list of text files (separated by blank space(s)) that the program will attempt to empty. If [FILE] is empty, then nothing happens.

For the list of options [OPTION], the following options are available:
-f, --force
      empty the file(s) by force if they exist, never prompt for confirmation

-y    do not prompt for confirmation and assume response as "yes" for all attempts to empty file(s) (essentially same as -f option)

-v, --verbose
      print messages to describe what is happening (by default, no descriptive message is printed, i.e. the program runs silently)

-h, --help
      print this help message and exit, do nothing else

Examples:
$ ./empty.out f1 f2 f3
Here, the files f1, f2, f3 will be emptied, i.e. will become blank text files, if user confirms with a response of "yes" for each file.

$ ./empty.out -f -v f1 f2
f1 and f2 will be emptied without any prompt for confirmation, and also messages will be printed to show what happened.

Author:
Written by Arunangshu Pal.
Last update: Monday 16 February 2026 02:33:15 AM IST
Tested. Working correctly. Monday 16 February 2026 02:33:15 AM IST
*/

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

#define FNAMEMAX 200
#define STRMAX 10

void cleanNewline(char *);
void clearfile(char *);

int main(int argc, char **arglist)
{
	int count = 0;
	int i, confirm;
	char *fname = new char[FNAMEMAX];
	char response[STRMAX], option[STRMAX];
	bool exists;

	bool verbose = false, force = false, help = false;

	for(i=1; i<argc; i++)
	{
		strcpy(option, *(arglist+i));
		if(strcmp(option, "-h") == 0 || strcmp(option, "--help") == 0)
			help = true;
		else if(strcmp(option, "-v") == 0 || strcmp(option, "--verbose") == 0)
			verbose = true;
		else if(strcmp(option, "-y") == 0)
			force = true;
		else if(strcmp(option, "-f") == 0 || strcmp(option, "--force") == 0)
			force = true;
	}
	
	if(help == true)
	{
		cout<<"Program Name:"<<endl;
		cout<<"empty - empty text files\n"<<endl;
		cout<<"Description:"<<endl;
		cout<<"When the program is run with a list of text files as command-line arguments, the files will be emptied, i.e. the contents of the files will be deleted (and the files themselves are not deleted). The usage syntax given below clarifies how the program works. Confirmation is taken from the user for each empty operation (default behaviour); only a response of \"yes\" will cause a file to be emptied."<<endl;
		cout<<endl;
		cout<<"Syntax:"<<endl;
		cout<<"$ <executabl> [OPTION] [FILE]"<<endl;
		cout<<"[FILE] is a list of text files (separated by blank space(s)) that the program will attempt to empty. If [FILE] is empty, then nothing happens."<<endl;
		cout<<"\nFor the list of options [OPTION], the following options are available:"<<endl;
		cout<<"-f, --force"<<endl;
		cout<<"      empty the file(s) by force if they exist, never prompt for confirmation\n"<<endl;
		cout<<"-y    do not prompt for confirmation and assume response as \"yes\" for all attempts to empty file(s) (essentially same as -f option)\n"<<endl;
		cout<<"-v, --verbose"<<endl;
		cout<<"      print messages to describe what is happening (by default, no descriptive message is printed, i.e. the program runs silently)\n"<<endl;
		cout<<"-h, --help"<<endl;
		cout<<"      print this help message and exit, do nothing\n"<<endl;
		cout<<"Examples:"<<endl;
		cout<<"$ ./empty.out f1 f2 f3"<<endl;
		cout<<"Here, the files f1, f2, f3 will be emptied, i.e. will become blank text files, if user confirms with a response of \"yes\" for each file."<<endl;
		cout<<endl;
		cout<<"$ ./empty.out -f -v f1 f2"<<endl;
		cout<<"f1 and f2 will be emptied without any prompt for confirmation, and also messages will be printed to show what happened."<<endl;
		return 0;
	}

	for(i = 1; i < argc; i++)
	{
		strcpy(fname, *(arglist+i));
		if(*fname == '-')
			continue;

		ifstream ipfs;
		ipfs.open(fname, ifstream::in);
		if(ipfs.fail() == true)
			exists = false;
		else
			exists = true;
		ipfs.close();

		if(exists == true)
		{
			if(force == true)
			{
				clearfile(fname);
				if(verbose == true)
					cout<<"File emptied: "<<fname<<endl;
			}
			else
			{
				cout<<"Are you sure you want to empty the file "<<fname<<"? [Enter \"yes\" to confirm] ";
				fgets(response, STRMAX, stdin);
				cleanNewline(response);
				confirm = strcmp(response, "yes");
				if(confirm == 0)
				{
					clearfile(fname);
					if(verbose == true)
						cout<<"File emptied: "<<fname<<endl;
				}
				else
				{
					if(verbose == true)
						cout<<"Nothing done. File not emptied: "<<fname<<endl;
				}
			}
		}
		else
		{
			if(verbose == true)
				cout<<"File not found: "<<fname<<endl;
		}
	}
	return 0;
}

void cleanNewline(char *s)
{
	char *i;
	for(i = s; *i != '\n' && *i != '\0'; i++);
	*i = '\0';
}

void clearfile(char *fname)
{
	ofstream opf;
	opf.open(fname, ofstream::out);
	opf.close();
}