#include "figure.h"

int main()
{
    Circle circle;
    char Figure[_STRING_LENGTH];
    int flag_circle = 0;
    int flag_staples = 0;

    printf("Введите данные фигуры согласно образцу:\n");
    printf("circle(0 0, 2.5)\n");
    printf("Ввод: ");
    fgets(Figure, _STRING_LENGTH, stdin);

    flag_staples = _if_staples(Figure);
    flag_circle = _if_is_circle(Figure);
    circle = coordinates(Figure);
    _check_coordinates(&circle);

    if (flag_circle) {
        printf("Name figure: ");

        if (flag_circle == IS_CIRCLE)
            printf("Circle");

        printf("\n");
    }

    else {
        printf("Название фигуры: INCORRECT\n");
    }

    if (!flag_staples) {
        printf("Скобки введены не по образцу.\n");
    }

    if (circle.flag_x)
        printf("Координата X: %.4f\n", circle.x);

    else
        printf("Координата X: INCORRECT\n");

    if (circle.flag_y)
        printf("Координата Y: %.4f\n", circle.y);
    else
        printf("Координата Y: INCORRECT\n");

    if (circle.flag_radius)
        printf("Радиус: %.4f\n", circle.radius);
    else
        printf("Радиус: INCORRECT\n");

    return 0;
}
