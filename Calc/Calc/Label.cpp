#include "Label.h"

Text Label::displayText() {
	text_.setString(data); // загружаем data в отображаемый текст
	return text_;
}