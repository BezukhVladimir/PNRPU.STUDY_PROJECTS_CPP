#include "Label.h"

Text Label::displayText() {
	text_.setString(data); // ��������� data � ������������ �����
	return text_;
}