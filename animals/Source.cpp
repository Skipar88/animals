#include<iostream>
#include<locale>
#include<windows.h>

using namespace std;

struct animals{
 char name[30];
 char type[20];
 int mouth_age;
 char person_name[40];
};

string fromDos(string dosString)
		{
			char buf[1000000];
			OemToCharA(dosString.c_str(), buf);
			return buf;
		}

int n;

int main(){
 animals animal[160];
 animals swap;

 setlocale(LC_ALL, "bulgarian");

 cout << "���� ������� (�� �� - ����� �� 5 � �� ������ �� 160): ";
 cin >> n;

 while (n < 5 || n > 160){
  cout << "������ ��� ��������� �� ���� �� ��������� �������, �������� ������ ���� ������ ��������� ������������!" << endl;
  cin >> n;
 }

 for (int i = 0; i < n; i++){
  cout << "��� �� ������� � " << i + 1 << " ";
  cin >> animal[i].name;
  cout << "��� �� ������� � " << i + 1 << " ";
  cin >> animal[i].type;
  cout << "������� � ��������� ������ �� ������� � " << i + 1 << " ";
  cin >> animal[i].mouth_age;
  cout << "���������� �� ������� � " << i + 1 << " ";
  cin >> animal[i].person_name;
 }

 cout << "******* ���������� �� ��� ����� *******" << endl;

 for (int i = 0; i < n; i++){

  cout << "������� � " << i + 1 << " " << fromDos (animal[i].name) << " " << fromDos (animal[i].type) << " " << animal[i].mouth_age << " " << fromDos (animal[i].person_name) << endl;

 }


 cout << "******* ����������� ����� *******" << endl;



 for (int i = 0; i < n - 1; i++)
 {
  for (int j = 0; j < n - i - 1; j++)
  {
   if (strcmp(animal[j].type, animal[j + 1].type) > 0)
   {
    swap = animal[j];
    animal[j] = animal[j + 1];
    animal[j + 1] = swap;
   }
   else if (strcmp(animal[j].type, animal[j + 1].type) == 0)
   {
    if (animal[j].mouth_age < animal[j+1].mouth_age)
    {
     swap = animal[j];
     animal[j] = animal[j + 1];
     animal[j + 1] = swap;
    }
   }
  }
 }

 for (int i = 0; i < n; i++)
 {
	double age_full = animal[i].mouth_age/12;
	double age_notfull = animal[i].mouth_age%12;
    cout << "������� � " << i + 1 << ", " << fromDos (animal[i].name) << ", " << fromDos (animal[i].type) << ", " << age_full <<" �. � "<< age_notfull <<" ������, " << fromDos (animal[i].person_name) <<endl;
 }

 cout << "******* �������� ��� �� ���������� *******" << endl;

 char person[40];
 cin >> person;

 for (int i = 0; i < n; i++){
 
	 if (fromDos (animal[i].person_name) == fromDos (person)){

		 for (int x = 0; x < n - 1; x++)
			 {
			  for (int j = 0; j < n - i - 1; j++)
			  {
			   if (strcmp(animal[j].name, animal[j + 1].name) > 0)
			   {
				swap = animal[j];
				animal[j] = animal[j + 1];
				animal[j + 1] = swap;
			   }
			   else if (strcmp(animal[j].name, animal[j + 1].name) == 0)
			   {
				if (animal[j].mouth_age < animal[j+1].mouth_age)
				{
				 swap = animal[j];
				 animal[j] = animal[j + 1];
				 animal[j + 1] = swap;
				}
			   }
			  }
			 }
		 int x = 0;
		 int sum = 0;
			 for (int y = 0; y < n; y++){ 
				 if (fromDos (animal[y].person_name) == fromDos (person)){
				 x++; 
				 sum += animal[y].mouth_age;
				 }
			 }
		 int average_full = sum/x/12;
		 int average_notfull = sum/x%12;
		 double age_full = animal[i].mouth_age/12;
		 double age_notfull = animal[i].mouth_age%12;
		 cout << "������� � " << i + 1 << ", " << fromDos (animal[i].name) << ", " << fromDos (animal[i].type) << ", " << age_full <<" �. � "<< age_notfull <<" ������, " << fromDos (animal[i].person_name) << ", ������ ������� �� ���������: "<< average_full <<" �. � " << average_notfull << " ������"<<endl;
	 }

 }

 system ("pause");
 return 0;
}