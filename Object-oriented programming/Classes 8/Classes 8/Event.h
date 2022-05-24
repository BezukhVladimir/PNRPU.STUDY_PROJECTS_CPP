#pragma once

enum class EventType
{
	EMPTY,    // ������ �������
	NOTEMPTY, // �� ������ �������
	ADD,      // �������� ������ � ������
	DELETE,   // ������� ������ �� ������
	GET,      // ������� ������� ���� ��������
	SHOW,     // ������� ��� ������ ��������
	MAKE,     // ������� ������
	QUIT      // �����
};

struct Event
{
	EventType type;

	union
	{
		EventType command; // �������

		struct
		{
			int message;
			int a; // �������� �������
		};
	};
};
