#include <graphics.h>
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <chrono>
#include <time.h>
#include<cstdlib>
#include<ctime>
#include <stdlib.h>
#include <fstream>
#include <cmath>
#include <vector>
#include <string>

using namespace std;
using namespace std::chrono;

// MAIN CLASS
class asteroid {
public:
	int score; // CURRENT SCORE
	int highest_score;
	string player; // PLAYER NAME
	int y = 440;
    int x = 0;
    int y_cor = 0;
    int random_val;
    int random_arr[100];
    vector<vector<double>> object_arr;

	asteroid() {
		score = 0;
		for (int i = 0; i <= 100; ++i) {
            random_arr[i] = i;
        }
	}

	// TO DISPLAY MENU PAGE
	void display_menu() {
		system("Color 71");
		cout << "\t\t\t" << "--(: ASTEROID CLASH :(--";
		cout << "\n\n\n\n\n\n";
		cout << "1) PLAY :) (Press 1)\n\n";
		cout << "2) SCORE (Press 2)\n\n";
		cout << "3) EXIT :( (Press 3)\n\n\n\n";
	}

	// COUNT TIME
	/*
	int count_time() {
        Sleep(1000);
        score += 1;
	}
	*/

	// TO CHECK IF GAME OVER
	bool game_over() {
	    double obstacle_arr[8][2] = {{random_val - 40, y}, {random_val - 20, y - 20}, {random_val, y - 40}, {random_val + 20, y - 20}, {random_val + 40, y}, {random_val + 20, y + 20}, {random_val, y + 40}, {random_val - 20, y + 20}};
	    double object_arr[8][3] = {{300 + x - 50, 400 + y_cor}, {300 + x - 25, 400 + y_cor - 25}, {300 + x, 400 + y_cor - 50}, {300 + x + 25, 400 + y_cor - 25}, {300 + x + 50, 400 + y_cor}, {300 + x + 25, 400 + y_cor + 25}, {300 + x, 400 + y_cor + 50}, {300 + x - 25, 400 + y_cor + 25}};
        /*
        for (int i = 1; i < 90; ++i) {
            vector<double> v1;
            for (int j = 0; i < 1; ++j) {
                double a = i * (3.14159 / 180);
                double res_y = (400 + y_cor) - 50 * sin(a);
                v1.push_back(res_y);
                double res_x = (300 + x) - 50 * cos(a);
                v1.push_back(res_x);
            }
            object_arr.push_back(v1);
        }

        for (int i = 91; i < 179; ++i) {
            vector<double> v1;
            for (int j = 0; i < 1; ++j) {
                double a = i * (3.14159 / 180);
                double res_y = (400 + y_cor) + 50 * sin(a);
                v1.push_back(res_y);
                double res_x = (300 + x) - 50 * cos(a);
                v1.push_back(res_x);
            }
            object_arr.push_back(v1);
        }

        for (int i = 181; i < 269; ++i) {
            vector<double> v1;
            for (int j = 0; i < 1; ++j) {
                double a = i * (3.14159 / 180);
                double res_y = (400 + y_cor) + 50 * sin(a);
                v1.push_back(res_y);
                double res_x = (300 + x) + 50 * cos(a);
                v1.push_back(res_x);
            }
            object_arr.push_back(v1);
        }

        for (int i = 271; i < 359; ++i) {
            vector<double> v1;
            for (int j = 0; i < 1; ++j) {
                double a = i * (3.14159 / 180);
                double res_y = (400 + y_cor) - 50 * sin(a);
                v1.push_back(res_y);
                double res_x = (300 + x) + 50 * cos(a);
                v1.push_back(res_x);
            }
            object_arr.push_back(v1);
        }

        vector <double> v2;
        v2.push_back(300 + x - 50);
        v2.push_back(400 + y_cor);
        object_arr.push_back(v2);

        vector <double> v3;
        v3.push_back(300 + x - 25);
        v3.push_back(400 + y_cor - 25);
        object_arr.push_back(v3);

        vector <double> v4;
        v4.push_back(300 + x);
        v4.push_back(400 + y_cor - 50);
        object_arr.push_back(v4);

        vector <double> v5;
        v5.push_back(300 + x + 25);
        v5.push_back(400 + y_cor - 25);
        object_arr.push_back(v5);

        vector <double> v6;
        v6.push_back(300 + x + 50);
        v6.push_back(400 + y_cor);
        object_arr.push_back(v6);

        vector <double> v7;
        v7.push_back(300 + x + 25);
        v7.push_back(400 + y_cor + 25);
        object_arr.push_back(v7);

        vector <double> v8;
        v8.push_back(300 + x);
        v8.push_back(400 + y_cor + 50);
        object_arr.push_back(v8);

        vector <double> v9;
        v9.push_back(300 + x - 25);
        v9.push_back(400 + y_cor + 25);
        object_arr.push_back(v9);
        */

        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                if (obstacle_arr[i][0] == object_arr[j][0] && obstacle_arr[i][1] == object_arr[j][1]) {
                    return true;
                }
            }
        }
	}

	// TO UPDATE HIGHEST SCORE
	void update_score() {
		if (score > highest_score) {
			highest_score = score;
			ofstream file;
			file.open("score.txt");
			file << player << " = " << "12";
			file.close();
		}
	}

    // TO RETURN A RANDOM COLUMN VALUE
    int random_col() {
		srand(time(0));
		int random_val = random_arr[rand() % 100];

		if (random_val % 2 == 0 && random_val % 3 == 0) {
            return 500;
		}
		else if (random_val % 2 == 0) {
            return 100;
		}
		else if (random_val % 3 == 0) {
            return 300;
		}
		else {
            return 500;
		}
    }

    // TO CHECK ND UPDATE COORDINATES
    void check_ycoordinates() {
		if (y != 440) {
            y += 1;
		}
		else {
		    random_val = random_col();
		    y = 40;
		}
	}
};

class child: asteroid {
public:

    child() {
        int gd = DETECT, gm;
        initgraph(&gd, &gm, "C:\\TC\\BGI");
    }

    void display() {
        cleardevice();
        check_ycoordinates();

        setfillstyle(XHATCH_FILL, RED);
        circle(random_val, y, 40);
        floodfill(random_val, y, WHITE);

        setfillstyle(XHATCH_FILL, BLUE);
        circle(300+x,400+y_cor,50);
        floodfill(300+x, 400+y_cor, WHITE);

        if(GetAsyncKeyState(VK_RIGHT)) {
            x += 1;
            display();
        }
        else if(GetAsyncKeyState(VK_LEFT)) {
            x -= 1;
            display();
        }
        else if(GetAsyncKeyState(VK_DOWN)) {
            y_cor += 1;
            display();
        }
        else if(GetAsyncKeyState(VK_UP)) {
            y_cor -= 1;
            display();
        }
        else {
            display();
        }
	}
};

int implement() {
    asteroid as;
    as.display_menu();
    int option;
    cout << "Enter ur choice: ";
    cin >> option;
    if (option == 1) {
        system("CLS");
        cout << "Please enter ur name: ";
        cin >> as.player;
        child chill;
        system("CLS");
        clock_t time;
        time = clock();
        while (as.game_over() != true) {
            chill.display();
        }
        time = clock() - time;
        as.score = (float)time/CLOCKS_PER_SEC;
        closegraph();
        as.update_score();
        implement();
    }
    else if (option == 2) {
        system("CLS");
        string line;
        ifstream myfile("score.txt");
        getline(myfile, line);
        if (line != "") {
            cout << line;
        }
        myfile.close();
        cout << "Press any button to go back";
        getch();
        implement();
    }
    else if (option == 3) {
        return 0;
    }
    else {
        system("CLS");
        cout << "Please enter a valid choice" << endl;
        implement();
    }
}

int main() {
    implement();
    return 0;
}

// TO OUTPUT 2 RANDOM COLUMN VALUES
	/*
	void random(int col_index[2]) {
		int col_arr[3] = { 0, 1, 2 }; // ARRAY CONTAINING COLUMN VALUES
		srand(time(0));
		int random_col1 = col_arr[rand() % 3]; // 1st RANDOM COLUMN VALUE
		int random_col2 = col_arr[rand() % 3]; // 2nd RANDOM COLUMN VALUE
		if (random_col2 == random_col1) {
			random(col_index);
		}
		col_index[0] = random_col1; // ARRAY CONTAINING 2 RANDOM COLUMN VALUES
		col_index[1] = random_col2;
	}

	// TO INCREASE DIFFICULTY
	void difficulty() {
		if (score >= 60) {
			int arr[2];
			random(arr);
			display(arr);
		}
	}

	// TO SLEEP FOR A RANDOM TIME DIFFERENCE BETWEEN TWO OBSTACLES
	void sleep() {
		int time;
		int i = 0;

		if (60 <= score < 120) {
			int time_srr[] = {0, 0.5, 1};
			int arr_size = sizeof(time_arr) / sizeof(time_arr[0]);
			sleep(random_num(time_arr, arr_size) * 1000);
		}

		else if (score >= 120) {
			int time_arr[] = {0, 0.25, 0.5};
			int arr_size = sizeof(time_arr) / sizeof(time_arr[0]);
			sleep(random_num(time_arr, arr_size * 1000));
		}
	}

	 // TO RETURN A RANDOM TIME DIFFERENCE
	int random_num(int arr[], int arr_size) {
		srand(time(0));
		int random_time = arr[rand() % arr_size];
		return random_time;
	}
	*/

