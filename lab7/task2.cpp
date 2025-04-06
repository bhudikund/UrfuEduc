#include <SFML/Graphics.hpp>
#include <ctime>
#include <cstdlib>
#include <cmath>


class Point {
public:
    int X, Y; // Координаты точки

    // Конструктор 
    Point(int x = 0, int y = 0) : X(x), Y(y) {}

    // Метод для получения текущих координат точки
    void Locat(int& x, int& y) {
        x = X;
        y = Y;
    }
};


class Krug : public Point {
private:
    int Radius;           // Радиус круга
    sf::Color Cvet;       // Цвет круга
    sf::CircleShape shape; // SFML-объект для отрисовки круга

public:
    // Конструктор 
    Krug(int x, int y, int radius, sf::Color cvet) : Point(x, y), Radius(radius), Cvet(cvet) {
        shape.setRadius(static_cast<float>(Radius));
        shape.setFillColor(Cvet);
        shape.setOrigin(static_cast<float>(Radius), static_cast<float>(Radius)); // Установка центра круга
        shape.setPosition(static_cast<float>(X), static_cast<float>(Y)); // Установка позиции круга
    }

    // Отображение круга
    void Show(sf::RenderWindow& window) {
        window.draw(shape);
    }

    // Скрытие круга (установка прозрачного цвета)
    void Hide(sf::RenderWindow& window) {
        shape.setFillColor(sf::Color::Transparent);
        window.draw(shape);
        shape.setFillColor(Cvet); // Возврат исходного цвета
    }

    // Изменение размера круга
    void ChangeSize(int delta) {
        Radius += delta;
        shape.setRadius(static_cast<float>(Radius));
        shape.setOrigin(static_cast<float>(Radius), static_cast<float>(Radius));
    }

    // Изменение цвета круга
    void ChangeColor(sf::Color newColor) {
        Cvet = newColor;
        shape.setFillColor(Cvet);
    }

    
    void Fly(int Cost, sf::RenderWindow& window) {
        Show(window);
        srand(static_cast<unsigned>(time(nullptr))); // Генератор случайных чисел
        do {
            int XX, YY;
            Locat(XX, YY);
            // Генерация новых координат
            do {
                XX = XX + static_cast<int>(round((rand() / static_cast<double>(RAND_MAX) - 0.5) * Cost);
            } while (XX <= 0 || XX >= window.getSize().x);
            do {
                YY = YY + static_cast<int>(round((rand() / static_cast<double>(RAND_MAX) - 0.5) * Cost);
            } while (YY <= 0 || YY >= window.getSize().y);
            
            Hide(window);
            X = XX;
            Y = YY;
            ChangeSize(rand() % 20 - 10); // Изменение размера на случайное значение
            ChangeColor(sf::Color(rand() % 255, rand() % 255, rand() % 255)); // Случайный цвет
            Show(window);
            window.display();
            sf::sleep(sf::milliseconds(300)); 
        } while (!sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)); 
    }
};


int main() {
    // Создание окна SFML
    sf::RenderWindow window(sf::VideoMode(800, 600), "Krug Program");

    // Создание круга
    Krug krug(200, 300, 50, sf::Color::Red);

    
    while (window.isOpen()) {
        sf::Event event;
        
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

       
        window.clear();
        krug.Fly(10, window); 
        window.display();
    }

    return 0;
}
