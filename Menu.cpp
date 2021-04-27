#include "Menu.h"

void Menu::gotoxy(int x, int y)
{
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
void Menu::clearScreen(int characterLength)
{
    for (int i = 0; i < characterLength; i++)
        cout << "\b";
}

void Menu::changeColour(int colour)
{
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTextAttribute(hConsole, colour);
}

void Menu::showBlinkColoour()
{
    string closed = "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~", open = "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
    int colour[] = { BLUE, WHITE, BLUE };
    cout << closed;
    for (int i = 0; i < 3; i ++)
    {
        Sleep(1000);
        clearScreen(34);
        changeColour(colour[i]);

        cout << open ;

        Sleep(1000);
        clearScreen(34);
        changeColour(WHITE);

        cout << closed ;
    }
    clearScreen(34);
    changeColour(WHITE);
}

void Menu::SimbolBoxListDraw()
{
    cout << endl << endl;
    cout << "tabela ASCII e Extendida para as box";
    cout << endl << endl;

    int tabela[] =
    { 185,186,187,188,200,201,202,203,204,206,
    191,192,217,218,179,196,193,194,195,197,221,180,
    45,47,60,62,88,91,92,93,94,95,238,240,
    30,31,176,177,178,219,220,223,254,
    59,123,124,125,143,205,189,190,207,241,242,245,249,46,58,61,127,174,175,145 };
    int j = 0;


    for (int i = 0; i < 62; i++)
    {
        cout << tabela[i] << '\t' << (char)tabela[i] << '\t';
        j++;
        if (j == 5) {
            cout << endl << endl;
            j = 0;
        }
    }
}

void Menu::Boat_1()
{

    gotoxy(20, 37); cout << "                __/___            " << endl;
    gotoxy(20, 38); cout << "          _____/______|           " << endl;
    gotoxy(20, 39); cout << "  _______/_____" << char(92) << "_______" << char(92) << "_____     " << endl;
    gotoxy(20, 40); cout << "  " << char(92) << "              < < <       |    " << endl;
    gotoxy(20, 41); cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;;
}
void Menu::Boat_2()
{
    gotoxy(73, 24); cout << "                                     |__" << endl;
    gotoxy(73, 25); cout << "                                     |" << char(92) << "/" << endl;
    gotoxy(73, 26); cout << "                                     ---" << endl;
    gotoxy(73, 27); cout << "                                     / | [" << endl;
    gotoxy(73, 28); cout << "                              !      | |||" << endl;
    gotoxy(73, 29); cout << "                            _/|     _/|-++'" << endl;
    gotoxy(73, 30); cout << "                        +  +--|    |--|--|_ |-" << endl;
    gotoxy(73, 31); cout << "                     { /|__|  |/" << char(92) << "__|  |--- |||__/" << endl;
    gotoxy(73, 32); cout << "                    +---------------___[}-_===_.'____               /"<< char(92) << endl;
    gotoxy(73, 33); cout << "                ____`-' ||___-{]_| _[}-  |     |_[___" << char(92) << "==--          " << char(92) << "/   _" << endl;
    gotoxy(73, 34); cout << " __..._____--==/___]_|__|_____________________________[___" << char(92) << "==--___,-----' .7" << endl;
    gotoxy(73, 35); cout << "|                                                                   BB-61/" << endl;
    gotoxy(73, 36); cout << " " << char(92) << "_______________________________________________________________________|" << endl;

}
void Menu::C_ascii() //Desenha NAVAL BATTLE no ecrã experiencia
{
    gotoxy(25, 7);  cout << "                                                                  ,--,      \n";
    gotoxy(25, 8);  cout << "         ,--.                                                  ,---.'|      \n";
    gotoxy(25, 9);  cout << "       ,--.'|     ,---,                          ,---,         |   | :      \n";
    gotoxy(25, 10); cout << "   ,--,:  : |    '  .' " << char(92) << "               ,---.    '  .' " << char(92) << "        :   : |      \n";
    gotoxy(25, 11); cout << ",`--.'`|  ' :   /  ;    '.            /__./|   /  ;    '.      |   ' :      \n";
    gotoxy(25, 12); cout << "|   :  :  | |  :  :       " << char(92) << "      ,---.;  ; |  :  :       " << char(92) << "     ;   ; '      \n";
    gotoxy(25, 13); cout << ":   |   " << char(92) << " | :  :  |   /" << char(92) << "   " << char(92) << "    /___/ " << char(92) << "  | |  :  |   /" << char(92) << "   " << char(92) << "    '   | |__    \n";
    gotoxy(25, 14); cout << "|   : '  '; |  |  :  ' ;.   :   " << char(92) << "   ;  " << char(92) << " ' |  |  :  ' ;.   :   |   | :.'|   \n";
    gotoxy(25, 15); cout << "'   ' ;.    ;  |  |  ;/  " << char(92) << "   " << char(92) << "   " << char(92) << "   " << char(92) << "  " << char(92) << ": |  |  |  ;/  " << char(92) << "   " << char(92) << "  '   :    ;   \n";
    gotoxy(25, 16); cout << "|   | | " << char(92) << "   |  '  :  | " << char(92) << "  " << char(92) << " ,'    ;   " << char(92) << "  ' .  '  :  | " << char(92) << "  " << char(92) << " ,'  |   |  ./    \n";
    gotoxy(25, 17); cout << "'   : |  ; .'  |  |  '  '--'       " << char(92) << "   " << char(92) << "   '  |  |  '  '--'    ;   : ;      \n";
    gotoxy(25, 18); cout << "|   | '`--'    |  :  :              " << char(92) << "   `  ;  |  :  :          |   ,/       \n";
    gotoxy(25, 19); cout << "'   : |        |  | ,'               :   " << char(92) << " |  |  | ,'          '---'        \n";
    gotoxy(25, 20); cout << ";   |.'        `--''                  '---" << char(32) << "   `- - " << char(39) << "" << char(39) << "                       \n";
    gotoxy(25, 21); cout << "'---'                                                                       \n";
    gotoxy(110, 7); cout << "                                      ,----,          ,----,     ,--,                 \n";
    gotoxy(110, 8); cout << "                                    ,/   .`|        ,/   .`|  ,---.'|                 \n";
    gotoxy(110, 9); cout << "    ,---,.      ,---,             ,`   .'  :      ,`   .'  :  |   | :         ,---,.  \n";
    gotoxy(110, 10); cout << "  ,'  .'  " << char(92) << "    '  .' " << char(92) << "          ;    ;     /    ;    ;     /  :   : |       ,'  .' |  \n";
    gotoxy(110, 11); cout << ",---.' .' |   /  ;    '.      .'___,/    ,'   .'___,/    ,'   |   ' :     ,---.'   |  \n";
    gotoxy(110, 12); cout << "|   |  |: |  :  :       " << char(92) << "     |    :     |    |    :     |    ;   ; '     |   |   .'  \n";
    gotoxy(110, 13); cout << ":   :  :  /  :  |   /" << char(92) << "   " << char(92) << "    ;    |.';  ;    ;    |.';  ;    '   | |__   :   :  |-,  \n";
    gotoxy(110, 14); cout << ":   |    ;   |  :  ' ;.   :   `----'  |  |    `----'  |  |    |   | :.'|  :   |  ;/|  \n";
    gotoxy(110, 15); cout << "|   :     " << char(92) << "  |  |  ;/  " << char(92) << "   " << char(92) << "      '   :  ;        '   :  ;    '   :    ;  |   :   .'  \n";
    gotoxy(110, 16); cout << "|   |   . |  '  :  | " << char(92) << "  " << char(92) << " ,'      |   |  '        |   |  '    |   |  ./   |   |  |-,  \n";
    gotoxy(110, 17); cout << "'   :  '; |  |  |  '  '--'        '   :  |        '   :  |    ;   : ;     '   :  ;/|  \n";
    gotoxy(110, 18); cout << "|   |  | ;   |  :  :              ;   |.'         ;   |.'     |   ,/      |   |    " << char(92) << "  \n";
    gotoxy(110, 19); cout << "|   :   /    |  | ,'              '---'           '---'       '---'       |   :   .'  \n";
    gotoxy(110, 20); cout << "|   | ,'     `--''                                                        |   | ,'    \n";
    gotoxy(110, 21); cout << "`----'                                                                    `----'      \n";
}

void Menu::C_ascii_2() // desenha battleship no ecra
{
    gotoxy(50, 7);   cout << "                                      ,----,          ,----,     ,--,                                                                    \n";
    gotoxy(50, 8);   cout << "                                    ,/   .`|        ,/   .`|  ,---.'|                                       ,--,            ,-.----.     \n";
    gotoxy(50, 9);   cout << "    ,---,.      ,---,             ,`   .'  :      ,`   .'  :  |   | :         ,---,.    .--.--.           ,--.'|     ,---,  " << char(92) << "    /  " << char(92) << "    \n";
    gotoxy(50, 10);  cout << "  ,'  .'  " << char(92) << "    '  .' " << char(92) << "          ;    ;     /    ;    ;     /  :   : |       ,'  .' |   /  /    '.      ,--,  | :  ,`--.' |  |   :    " << char(92) << "   \n";
    gotoxy(50, 11);  cout << ",---.' .' |   /  ;    '.      .'___,/    ,'   .'___,/    ,'   |   ' :     ,---.'   |  |  :  /`. /   ,---.'|  : '  |   :  :  |   |  ." << char(92) << " :  \n";
    gotoxy(50, 12);  cout << "|   |  |: |  :  :       " << char(92) << "     |    :     |    |    :     |    ;   ; '     |   |   .'  ;  |  |--`    |   | : _' |  :   |  '  .   :  |: |  \n";
    gotoxy(50, 13);  cout << ":   :  :  /  :  |   /" << char(92) << "   " << char(92) << "    ;    |.';  ;    ;    |.';  ;    '   | |__   :   :  |-,  |  :  ;_      :   : |.'  |  |   :  |  |   |   " << char(92) << " :  \n";
    gotoxy(50, 14);  cout << ":   |    ;   |  :  ' ;.   :   `----'  |  |    `----'  |  |    |   | :.'|  :   |  ;/|   " << char(92) << "  " << char(92) << "    `.   |   ' '  ; :  '   '  ;  |   : .   /  \n";
    gotoxy(50, 15);  cout << "|   :     " << char(92) << "  |  |  ;/  " << char(92) << "   " << char(92) << "      '   :  ;        '   :  ;    '   :    ;  |   :   .'    `----.   " << char(92) << "  '   |  .'. |  |   |  |  ;   | |`-'   \n";
    gotoxy(50, 16);  cout << "|   |   . |  '  :  | " << char(92) << "  " << char(92) << " ,'      |   |  '        |   |  '    |   |  ./   |   |  |-,    __ " << char(92) << "  " << char(92) << "  |  |   | :  | '  '   :  ;  |   | ;      \n";
    gotoxy(50, 17);  cout << "'   :  '; |  |  |  '  '--'        '   :  |        '   :  |    ;   : ;     '   :  ;/|   /  /`--'  /  '   : |  : ;  |   |  '  :   ' |      \n";
    gotoxy(50, 18);  cout << "|   |  | ;   |  :  :              ;   |.'         ;   |.'     |   ,/      |   |    " << char(92) << "  '--'.     /   |   | '  ,/   '   :  |  :   : :      \n";
    gotoxy(50, 19);  cout << "|   :   /    |  | ,'              '---'           '---'       '---'       |   :   .'    `--'---'    ;   : ;--'    ;   |.'   |   | :      \n";
    gotoxy(50, 20);  cout << "|   | ,'     `--''                                                        |   | ,'                  |   ,/        '---'     `---'.|      \n";
    gotoxy(50, 21);  cout << "`----'                                                                    `----'                    '---'                     `---`      \n";
}

void Menu::intro()
{
    gotoxy(80, 7);   cout << "                         .sssssssss.";
    gotoxy(80, 8);   cout << "                   .sssssssssssssssssss";
    gotoxy(80, 9);   cout << "                 sssssssssssssssssssssssss";
    gotoxy(80, 10);   cout << "                ssssssssssssssssssssssssssss";
    gotoxy(80, 11);   cout << "                 @@sssssssssssssssssssssss@ss";
    gotoxy(80, 12);   cout << "                 |s@@@@sssssssssssssss@@@@s|s";
    gotoxy(80, 13);   cout << "          _______|sssss@@@@@sssss@@@@@sssss|s";
    gotoxy(80, 14);   cout << "        /         sssssssss@sssss@sssssssss|s";
    gotoxy(80, 15);   cout << "       /  .------+.ssssssss@sssss@ssssssss.|";
    gotoxy(80, 16);   cout << "      /  /       |...sssssss@sss@sssssss...|";
    gotoxy(80, 17);   cout << "     |  |        |.......sss@sss@ssss......|";
    gotoxy(80, 18);   cout << "     |  |        |..........s@ss@sss.......|";
    gotoxy(80, 19);   cout << "     |  |        |...........@ss@..........|";
    gotoxy(80, 20);   cout << "      " << char(92) << "  " << char(92) << "       |............ss@..........|";
    gotoxy(80, 21);   cout << "       " << char(92) << "  '------+...........ss@...........|";
    gotoxy(80, 22);   cout << "        " << char(92) << "________ .........................|";
    gotoxy(80, 23);   cout << "                 |.........................|";
    gotoxy(80, 24);   cout << "                /..........................." << char(92) << "";
    gotoxy(80, 25);   cout << "               |.............................|";
    gotoxy(80, 26);   cout << "                  |.......................|";
    gotoxy(80, 27);   cout << "                      |...............|";
   // gotoxy(80, 30);   cout << "            __   __  __ ___  __   __   __  __  __";
   // gotoxy(80, 31);   cout << "           |__) |_  (_   |  |_   |__) |_  |_  |__)";
   // gotoxy(80, 32);   cout << "           |__) |__ __)  |  |__  |__) |__ |__ | " << char(92) << "";
    gotoxy(80, 40);   cout << "            MADE BY JOSE MAGALHAES & LEOANARDO BOTELHO";

    gotoxy(81, 30);   cout << "   ___  __ .  .  _   __  __        _    __ ___  __   __   ";
    gotoxy(81, 31);   cout << "    |  |_  |" << char(92) << " | | " << char(92) << " |_  (_        /_" << char(92) << "  |_   |  |_   |__) ";
    gotoxy(81, 32);   cout << "    |  |__ | " << char(92) << "| |_/ |__ __)      /   " << char(92) << " |    |  |__  | " << char(92) ;
    
    gotoxy(83, 34);   cout << "                __ ___       _     __";
    gotoxy(83, 35);   cout << "               (_   |  |  | | " << char(92) << " | |  |";
    gotoxy(83, 36);   cout << "               __)  |  |__| |_/ | |__|";
}
void Menu::Mostar_Intro()
{
    Menu M;
    int num = 3;
    bool running = true;
    do
    {
        M.intro();
        num--;
        Sleep(1000);
        system("cls");

        if (num == 0)
            running = false;

    } while (running != false);
}
void Menu::loading_s()
{
   gotoxy(80, 30);   cout << "           __    _    _  . .  .  __   ";
   gotoxy(80, 31);   cout << "     |    |  |  /_" << char(92) << "  | " << char(92) << " | |" << char(92) << " | | __  ";
   gotoxy(80, 32);   cout << "     |__  |__| /   " << char(92) << " |_/ | | " << char(92) << "| |__|  ";
   
   for (int i = 0; i < 5; i + 2) {
   gotoxy(80, 32);   cout << "";
   }

}

void Menu::M_Menu(void)
{
    int menu_item = 1, run, y = 46, num = 3;
    bool running = true;
    bool running_i = true;
    Menu M;
    Menu M1;
    Menu M2;
    
    M2.Mostar_Intro();
    M.C_ascii_2();
    M1.Boat_2();
    gotoxy(100, 45); cout << "Main Menu";
    gotoxy(100, 46); cout << "->";
   
    gotoxy(95, 42); cout << char(218);  //canto superior esquerdo
    gotoxy(95, 53); cout << char(192);  //canto inferior esquerdo
    gotoxy(121, 42); cout << char(191); //canto superior direito
    gotoxy(121, 53); cout << char(217); //canto inferior direito

    for (int i = 1; i <= 25; i++)
    {
        gotoxy(95 + i, 42); cout << char(196); //linha de cima
        gotoxy(95 + i, 53); cout << char(196); // linha de baixo
    }

    for (int j = 1; j <= 10; j++ ) 
    {
        gotoxy(95, 42 + j); cout << char(179); //linha da esquerda
        gotoxy(121, 42 + j); cout << char(179); //linha da direita
    }

    while(running)
    {
        
        gotoxy(102, 46); cout << " [+] NEW GAME ";
        gotoxy(102, 47); cout << " [+] DEMO ";
        gotoxy(102, 48); cout << " [+] LAST GAME ";       
        gotoxy(102, 49); cout << " [+] INFO ";       
        gotoxy(102, 50); cout << " [+] QUIT ";

        system("pause>nul"); // the >nul bit causes it the print no message
        
        if (GetAsyncKeyState(VK_DOWN) && y != 50) //down button pressed
        {
            gotoxy(100, y); cout << "  ";
            y++;
            gotoxy(100, y); cout << "->";
            menu_item++;
            continue;

        }

        if (GetAsyncKeyState(VK_UP) && y != 46) //up button pressed
        {
            gotoxy(100, y); cout << "  ";
            y--;
            gotoxy(100, y); cout << "->";
            menu_item--;
            continue;
        }


        if (GetAsyncKeyState(VK_RETURN)) // Enter key pressed
        {
            switch (menu_item) 
            {

                case 1: 
                {
                gotoxy(102, 56);
                cout << "U chose new game "; //return new game e colocar running = false
                break;
                }


                case 2: 
                {
                gotoxy(102, 56); // introduzir a demo
                battleShip.Demo();
                break;
                }

                case 3: 
                {
                gotoxy(102, 56);
                cout << "U chose last game "; // return last game e coloca running = false
                break;
                }

                case 4: 
                {
                gotoxy(102, 56);
                cout << "\nBattleship!\nThis game is still a demo under development within the scope of the subject LAB 2nd Semester 2020/2021.\nMade by Jose Rocha & Leonardo Botelho.\nHave fun! ";
                break;
                }

                case 5: {
                gotoxy(102, 56);
                cout << "Quiting the game";
                running = false;
                }

            }

        }

    }

   // gotoxy(100, 62);
        
}