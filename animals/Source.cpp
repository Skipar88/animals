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

 cout << "Борй любимци (не по - малко от 5 и не повече от 160): ";
 cin >> n;

 while (n < 5 || n > 160){
  cout << "Грешка при въвеждане на броя на домашните любимци, въветеде тяхния брой отново съобразно инструкциите!" << endl;
  cin >> n;
 }

 for (int i = 0; i < n; i++){
  cout << "Име на любимец № " << i + 1 << " ";
  cin >> animal[i].name;
  cout << "Вид на любимец № " << i + 1 << " ";
  cin >> animal[i].type;
  cout << "Възраст в навършени месеци на любимец № " << i + 1 << " ";
  cin >> animal[i].mouth_age;
  cout << "Собственик на любимец № " << i + 1 << " ";
  cin >> animal[i].person_name;
 }

 cout << "******* Въведените от Вас данни *******" << endl;

 for (int i = 0; i < n; i++){

  cout << "Любимец № " << i + 1 << " " << fromDos (animal[i].name) << " " << fromDos (animal[i].type) << " " << animal[i].mouth_age << " " << fromDos (animal[i].person_name) << endl;

 }


 cout << "******* Сортираните данни *******" << endl;



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
    cout << "Любимец № " << i + 1 << ", " << fromDos (animal[i].name) << ", " << fromDos (animal[i].type) << ", " << age_full <<" г. и "<< age_notfull <<" месеца, " << fromDos (animal[i].person_name) <<endl;
 }

 cout << "******* Въведете име на собственик *******" << endl;

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
		 cout << "Любимец № " << i + 1 << ", " << fromDos (animal[i].name) << ", " << fromDos (animal[i].type) << ", " << age_full <<" г. и "<< age_notfull <<" месеца, " << fromDos (animal[i].person_name) << ", средна възраст на любимците: "<< average_full <<" г. и " << average_notfull << " месеца"<<endl;
	 }

 }

 system ("pause");
 return 0;
}