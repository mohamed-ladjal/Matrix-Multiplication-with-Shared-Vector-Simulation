#include<bits/stdc++.h>

#include <windows.h>

#include <chrono>

#include <thread>

#include <mmsystem.h>

#include <dos.h> //for delay

#include <conio.h>

#pragma comment(lib, "winmm.lib")
#define white FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE
#define green FOREGROUND_INTENSITY | FOREGROUND_GREEN
#define red FOREGROUND_INTENSITY | FOREGROUND_RED
#define blue FOREGROUND_INTENSITY | FOREGROUND_BLUE
#define yellow FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN
#define purple FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE
#define bwhite BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE
#define bgreen BACKGROUND_INTENSITY | BACKGROUND_GREEN
#define bred BACKGROUND_INTENSITY | BACKGROUND_RED
#define bblue BACKGROUND_INTENSITY | BACKGROUND_BLUE
#define byellow BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN
#define bpurple BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_BLUE

using namespace std;
using namespace std::chrono; // nanoseconds, system_clock, seconds

void ResetConsoleColour(WORD Attributes) {
   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Attributes);
}

void SetConsoleColour(WORD * Attributes, DWORD Colour, int text) {

   CONSOLE_SCREEN_BUFFER_INFO Info;
   HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
   GetConsoleScreenBufferInfo(hStdout, & Info);
   * Attributes = Info.wAttributes;
   SetConsoleTextAttribute(hStdout, Colour);
   printf("%2d", text);
   fflush(stdout);
   ResetConsoleColour( * Attributes);
}
void SetTitle(WORD * Attributes, DWORD Colour, string text) {

   CONSOLE_SCREEN_BUFFER_INFO Info;
   HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
   GetConsoleScreenBufferInfo(hStdout, & Info);
   * Attributes = Info.wAttributes;
   SetConsoleTextAttribute(hStdout, Colour);
   // printf("%s",text);
   cout << text;
   
   
   ResetConsoleColour( * Attributes);
}

vector < int > DecaleVector(vector < int > v, float s) {
   //Beep(500,s*300);
   int temp = v[0];
   for (int i = 0; i < v.size(); i++) {
      v[i] = v[i + 1];
   }
   v[v.size() - 1] = temp;
   //Sleep(1000);
   return v;
}

int main() {
    WORD Attributes = 0;
   srand(time(0));
   vector < int > my_vect;

   int mat[100][100];
   cout << "Dimenstion (vector/matrix):";
   int n;
   cin >> n;
   vector < int > res_vect(n, 0);
   cout << "Random generation ? (y/n): ";
   int R = (int)
   'y';
   R = getch();
   if ((char) R != 'y') {
      cout << "\n";
      for (int i = 0; i < n; i++) {
         for (int j = 0; j < n; j++) {
            cout << "mat[" << i << "][" << j << "]= ";
            int a;
            cin >> a;
            mat[i][j] = a;
         }
      }
      cout << "\n\n";
      for (int i = 0; i < n; i++) {
         cout << "vector[" << i << "] =";
         int a;
         cin >> a;
         my_vect.push_back(a);
         cout << "\n";
      }

   } else {
      for (int i = 0; i < n; i++) {
         my_vect.push_back(rand() % 100);
      }

      for (int i = 0; i < n; i++) {
         for (int j = 0; j < n; j++) {
            mat[i][j] = (rand() % 100);

         }

      }
   }

   cout << "\nDelay in sec :";
   float s;
   cin >> s;

   cout << "play sound ? (y/n): ";
   int c = (int)
   'y';
   c = getch();
   bool playing_sound;
   if ((char) c == 'y' && s >= 0.6) {
      playing_sound = true;
   } else {
      playing_sound = false;
   }

   cout << (char) c;
   system("cls");

   vector < int > v1;
   vector < int > v2;
   vector < int > v3;
   vector < int > v4;
   for (int i = 0; i < n; i += 1) {
      v1.push_back(i);
      v2.push_back(i);
   }
   int l = 0;
   int k = 0;
   int kk = 0;
   int ll = 0;
   int p1, p2;
   int total = 0;
   int col = 0;
   string operation = "";
   int u = 0;
   bool status = false, decal = false;
   string current;

   while (1)

   {
      if (GetKeyState(VK_SPACE)) {

         system("pause");
      }

      system("cls");

   
      
   
      

      SetTitle( & Attributes, bgreen, "                                                                \n               MATRIX x SHARED_VECTRO SIMULATION                \n                                                                \n\n\n\n");

      if (playing_sound)
         Beep(300, s * 50);

      for (int i = 0; i < n; i++) {
         if (i == 0) {
      
		 
            cout << "ID    STATUS    ";
   
	    
            for (int r = 0; r < n * 2; r++) {
               if (r == n)
                  cout << "MATRIX";
	       
               else cout << "  ";
	       fflush(stdout);
            }
            cout << "VECTOR    RESULT";
   
	    

            cout << "\n";
      
	    
            cout << "___________________________________________________________________________";
            cout << "\n\n";
   

         }
      
	 
         cout << "PE" << i << " ";
   
	 
         if (i == u) {
      
		 
            SetTitle( & Attributes, bgreen | white, "(Active)  ");
            current = "PE" + to_string(i);

         } else {
      
		 
            SetTitle( & Attributes, bred | white, "(InActive)");
         }
      

         cout << " ";
         for (int j = 0; j < n; j++) {
      
		 
            if (i == v1[i] && j == v2[i] && l == v1[i] && v1.size() > 0) {

               SetConsoleColour( & Attributes, bblue | white, mat[i][j]);

               operation = to_string(mat[i][j]) + " X " + to_string(my_vect[i]) + " + " + to_string(res_vect[i]);
               res_vect[i] += mat[i][j] * my_vect[i];
               total++;
               col++;
            } else if (v1.size() == 0 && i == v3[j] && j == v4[j] && ll == v4[j]) {

               SetConsoleColour( & Attributes, bblue | white, mat[i][j]);
               operation = to_string(mat[i][j]) + " X " + to_string(my_vect[i]) + " + " + to_string(res_vect[i]);

               res_vect[i] += mat[i][j] * my_vect[i];
               col++;

               total++;

            } else {
               SetConsoleColour( & Attributes, green, mat[i][j]);
            }

            cout << "  ";

         }

         cout << "    |  ";

         if (i == u) {
            SetConsoleColour( & Attributes, bblue | white, my_vect[i]);

            cout << "  |  ";
            SetConsoleColour( & Attributes, bblue | white, res_vect[i]);
         } else {
            SetConsoleColour( & Attributes, red, my_vect[i]);
            cout << "  |  ";
            SetConsoleColour( & Attributes, yellow, res_vect[i]);

         }

         //cout << "\n______________________________________________________________\n"; 
   
	 

         cout << "\n\n";
   
	 

      }
      l++;
      // if(k%2!=0){
      //v1.pop_back();
      //v2.erase(v2.begin());
      //k++;
      //l=0;
      //}
      //if(col>=n){
      //col%=n;

      //}
      u++;
      if ((l == (n - k) || l >= n) && v1.size() > 0 && v2.size() > 0) {
         k++;
         v1.pop_back();
         v2.erase(v2.begin());

         u %= (n - (n - u));
         l = l % (n - k + 1);
         if (v1.size() == 0)
            u = n - 1;
         decal = true;
      }
      if (v1.size() == 0 && kk > 0)
         ll++;
      if (ll == kk && v1.size() <= 0 && kk < n - 1) {
         v3.insert(v3.begin(), n - kk - 1);
         v4.push_back(kk);

         u = n - ll - 1;
         ll = 0;
         kk++;

         decal = true;

      }

      cout << "\n";
      
      
      cout << "___________________________________________________________________________\n\n";
   
      
   
      
      cout << "current operation : ";
      SetTitle( & Attributes, bgreen | red, operation);
            cout << " | Active PE : ";
   
	    
      SetTitle( & Attributes, bgreen | red, current);
      cout << "  | total : ";
   
      
      SetTitle( & Attributes, bgreen | red, " " + to_string(total) + " ");

      cout << "\n\n";
      

           cout << "___________________________________________________________________________\n";
   
	   
      
 

      cout << "\n\n               Press SPACE to pause ....\n\n";
   
      
      if (decal) {

         my_vect = DecaleVector(my_vect, s);
         decal = false;
         Beep(400,s*300);

           //PlaySound(TEXT("Bleep.wav"),NULL,SND_FILENAME);	 
         Sleep(s * 2000);
      }
      Sleep(s * 1000);
      if (total >= n * n) {

         PlaySound(TEXT("elevator.wav"), NULL, SND_FILENAME);
         //Beep(1000,1000);
         break;
      }

   }
   return 0;
}
