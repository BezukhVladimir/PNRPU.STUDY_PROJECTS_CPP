#include "engine.h"

void setOperation(DialogBox* dialog, const string& operation)
{
	if (!isdigit(dialog->data.back())) {
		stringstream ss;
		ss << dialog->data;
		getline(ss, dialog->data, ' ');
	}

	dialog->data += " " + operation;
	dialog->operation = operation;
}

void emptyDialog(DialogBox* dialog, InputBox* input, const string& operation)
{
	if (input->data.back() == '.')
		input->data.erase(input->data.size() - 1, 1);
	dialog->data =
		input->data + " " + operation;
	dialog->value
		= stod(input->data);
	dialog->operation = operation;
	input->data = "0";
}

void fixedSetprecision(DialogBox* left, InputBox* right) {
	stringstream ss;
	ss << fixed << setprecision(10) << left->value;
	left->data = ss.str();
	size_t pos = left->data.find_last_not_of('0');
	if (pos != string::npos) left->data.erase(pos + 1);
	if (left->data.back() == '.')
		left->data += '0';
	left->operation = "";
	right->data = "0";
}

void fixedInput(InputBox* input) {
	stringstream ss;
	ss << fixed << setprecision(10) << input->data;
	input->data = ss.str();
	size_t pos = input->data.find_last_not_of('0');
	if (pos != string::npos) input->data.erase(pos + 1);
	if (input->data.back() == '.')
		input->data += "0";
}

void fixedDialog(DialogBox* dialog) {
	stringstream ss;
	ss << fixed << setprecision(10) << dialog->data;
	dialog->data = ss.str();
	size_t pos = dialog->data.find_last_not_of('0');
	if (pos != string::npos) dialog->data.erase(pos + 1);
	if (dialog->data.back() == '.')
		dialog->data += "0";
	dialog->operation = "";
}

void calculate(DialogBox* left, InputBox* right)
{
	if (left->operation == "+")
		left->value = sum(left->value, stod(right->data));
	else if (left->operation == "-")
		left->value = dif(left->value, stod(right->data));
	else if (left->operation == "*")
		left->value = mult(left->value, stod(right->data));
	else if (left->operation == "/")
		left->value = div(left->value, stod(right->data));
	else if (left->operation == "^")
		left->value = myPower(left->value, stod(right->data));
	else if (left->operation == "%")
		left->value = myRemainder(left->value, stod(right->data));

	fixedSetprecision(left, right);
}

void simpleEvent(DialogBox* left, InputBox* right, const string& op)
{
	if (left->data == ""     ||	left->data == OVERLOAD    ||
		left->data == "inf"  || left->data == "nan(ind)"  ||
		left->data == "-inf" || left->data == "-nan(ind)" ||
		left->data == "+inf" || left->data == "+nan(ind)") {
		emptyDialog(left,
			right,
			op);
	}
	else
	{
		setOperation(left, op);
	}
}

void solveEvent(DialogBox* left, InputBox* right)
{
	if (left->data == OVERLOAD ||
		left->data == "inf"    || left->data == "nan(ind)"  ||
		left->data == "-inf"   || left->data == "-nan(ind)" ||
		left->data == "+inf"   || left->data == "+nan(ind)")
		left->data = "";
	else if (!left->data.empty())
	{
		if (!isdigit(left->data.back()))
			calculate(left, right);
	}
}

void clearEvent(DialogBox* d, InputBox* i, const string& operation)
{
	if (operation != "CE") {
		d->data = "";
		d->value = 0.0;
		d->operation = "";
	}

	i->data = "0";
}