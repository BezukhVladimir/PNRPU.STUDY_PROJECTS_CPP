#pragma once

enum class EventType
{
	EMPTY,    // пустое событие
	NOTEMPTY, // не пустое событие
	ADD,      // добавить объект в группу
	DELETE,   // удалить объект из группы
	GET,      // вывести атрибут всех объектов
	SHOW,     // вывести всю группу объектов
	MAKE,     // создать группу
	QUIT      // выход
};

struct Event
{
	EventType type;

	union
	{
		EventType command; // команда

		struct
		{
			int message;
			int a; // параметр команды
		};
	};
};
