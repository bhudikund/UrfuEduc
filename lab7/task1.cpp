
#include <SFML/Graphics.hpp>  
#include <cmath>              
#include <cstdlib>            
#include <ctime>             


class Point {
public:
    int X, Y;         
    sf::Color Cvet;  

    // Метод инициализации точки
    void Init(int XN, int YN, sf::Color Color) {
        X = XN;
        Y = YN;
        Cvet = Color;
    }

    // Виртуальные методы для отображения и скрытия точки
    virtual void Show(sf::RenderWindow& window) {}
    virtual void Hide(sf::RenderWindow& window) {}

    // Метод для получения текущих координат точки
    void Locat(int& XL, int& YL) {
        XL = X;
        YL = Y;
    }

   
    void Fly(int Cost, sf::RenderWindow& window) {
        Show(window);  

        // Инициализация генератора случайных чисел
        srand(static_cast<unsigned>(time(nullptr)));

       
        do {
            int XX, YY;
            Locat(XX, YY);  // Получить текущие координаты

            // Генерация новой координаты X с учетом границ окна
            do {
                // Случайное смещение
                XX = XX + static_cast<int>(round((rand() / static_cast<double>(RAND_MAX) - 0.5) * Cost));
            } while (XX <= 0 || XX >= window.getSize().x);  // Проверка границ

            // Генерация новой координаты Y с учетом границ окна
            do {
                YY = YY + static_cast<int>(round((rand() / static_cast<double>(RAND_MAX) - 0.5) * Cost));
            } while (YY <= 0 || YY >= window.getSize().y);  // Проверка границ

            // Перемещение точки
            Hide(window);   
            X = XX;        
            Y = YY;
            Show(window);  

            window.display();                  // Обновить отображение окна
            sf::sleep(sf::milliseconds(300)); 

        } while (!sf::Keyboard::isKeyPressed(sf::Keyboard::Escape));  // Условие выхода
    }
};


class Krug : public Point {
public:
    unsigned short Radius;  // Радиус круга
    sf::CircleShape shape;  // SFML-объект круга

    // Конструктор круга
    Krug(int XN, int YN, unsigned short R, sf::Color Color) : shape(R) {
        Init(XN, YN, Color);  
        Radius = R;
        shape.setFillColor(Cvet);      
        shape.setPosition(static_cast<float>(X), static_cast<float>(Y)); 
    }

    // Метод отображения круга
    void Show(sf::RenderWindow& window) override {
        window.draw(shape);
    }

    // Метод скрытия круга (рисует черным цветом)
    void Hide(sf::RenderWindow& window) override {
        shape.setFillColor(sf::Color::Black);  
        window.draw(shape);
        shape.setFillColor(Cvet);  
    }
};


int main() {
    // Создание окна размером 800x600 с заголовком
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");

    // Создание красного круга с центром в (150,40) и радиусом 50
    Krug TestKrug(150, 40, 50, sf::Color::Red);

 
    while (window.isOpen()) {
        sf::Event event;
      
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close(); 
        }

        window.clear();              
        TestKrug.Fly(100, window); 
        window.display();         
    }

    return 0;
}
