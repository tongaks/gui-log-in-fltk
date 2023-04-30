#include <iostream>
#include <string>
#include <cstring>
#include <stdio.h>
#include <fstream>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Output.H>

using namespace std;

void check(Fl_Widget* widget, void* data)/*Fl_Widget need a parameter that points to widget like Fl_Button or Fl_Input. it is specified inside the function*/ {
	Fl_Input *username = (Fl_Input*) widget->parent()->child(0); //get user name(child(0)) value
	Fl_Input *password = (Fl_Input*) widget->parent()->child(1); //get password(child(1)) value

	string username_val = username->value();
	string password_val = password->value();

	//use fl_box instead of fl_output

	if (strcmp(username_val.c_str(), "dsf") == 0 && strcmp(password_val.c_str(), "123") == 0) {
		Fl_Output *output = (Fl_Output*) data;
		output->value("correct");
	} else {
		Fl_Output *output = (Fl_Output*) data;
		output->value("wrong");
	}
}

int main(int argc, char const *argv[])
{
	Fl_Window *window = new Fl_Window(500, 300, "Softwere");
	Fl_Input *input = new Fl_Input(220, 100, 100, 30, "User Name"); //first child
	Fl_Input *input_text = new Fl_Input(220, 150, 100, 30, "Password"); //second child
	Fl_Button *button = new Fl_Button(10, 100, 70, 30, "Submit"); //3rd child
	Fl_Output *correct = new Fl_Output(220, 200, 100, 20, "result"); //its value will be speified in the callback, so the "result" is the title

	button->callback(check, correct);
	window->end();
	window->show();
	return Fl::run();
}