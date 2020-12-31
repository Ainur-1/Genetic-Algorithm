#include <SFML/Graphics.hpp>

using namespace sf;

int demo()
{
	// ������, �������, ����������, �������� ������� ����� ����������
	RenderWindow window(VideoMode(500, 500), "SFML Works!");

	// ������� ���� ����������. �����������, ���� ������� ����
	while (window.isOpen())
	{
		// ������������ ������� ������� � �����
		Event event;
		while (window.pollEvent(event))
		{
			// ������������ ����� �� �������� � ����� ������� ����?
			if (event.type == Event::Closed)
				// ����� ��������� ���
				window.close();
		}
		// ������ ���� ����
		window.clear(sf::Color::Black);

		
		// ��������� ����	
		window.display();
	}

	return 0;
}