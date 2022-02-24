#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _TRUE         1
#define _FALSE        0
#define _STRING_LENGTH 50
#define _INVALID_VALUE -919939
#define IS_CIRCLE    11

typedef struct
{
  float x;
  float y;
  float radius;
  int flag_x;
  int flag_y;
  int flag_radius;
} Circle;

int _if_is_circle(char *figure)
{
  if ((figure[0] == 'c' || figure[0] == 'C') &&
      (figure[1] == 'i' || figure[1] == 'I') &&
      (figure[2] == 'r' || figure[2] == 'R') &&
      (figure[3] == 'c' || figure[3] == 'C') &&
      (figure[4] == 'l' || figure[4] == 'L') &&
      (figure[5] == 'e' || figure[5] == 'E'))
  {
    return IS_CIRCLE;
  }
  else
    return _FALSE;
}

int _if_staples(char *figure)
{
  int i = 0;

  while (figure[i] != '(')
  {
    if (i == strlen(figure))
      return _FALSE;
    i++;
  }
  while (figure[i] != ')')
  {
    if (i == strlen(figure))
      return _FALSE;
    i++;
  }

  return _TRUE;
}

Circle coordinates(char *figure)
{
  Circle coordinates = {.x = _INVALID_VALUE,
                        .y = _INVALID_VALUE,
                        .radius = _INVALID_VALUE,
                        .flag_x = 1,
                        .flag_y = 1,
                        .flag_radius = 1};
  char coordinateX[_STRING_LENGTH];
  char coordinateY[_STRING_LENGTH];
  char radius[_STRING_LENGTH];
  int i = 0;
  while (!(isdigit(figure[i])))
  {
    if (i == strlen(figure))
      break;

    i++;
  }

  int j = 0;

  while (figure[i] != ' ')
  {
    if (i == strlen(figure))
      break;

    coordinateX[j] = figure[i];
    j++;
    i++;
  }

  j = 0;

  while (figure[i] != ',')
  {
    if (i == strlen(figure))
      break;

    coordinateY[j] = figure[i];
    j++;
    i++;
  }

  j = 0;

  while (!(isdigit(figure[i])))
  {
    if (i == strlen(figure))
      break;

    i++;
  }

  while (figure[i] != ')')
  {
    if (i == strlen(figure))
      break;

    radius[j] = figure[i];
    j++;
    i++;
  }
  if (coordinateX[i] == '.' && !(isdigit(coordinateX[i + 1])))
    coordinates.flag_x = 0;
    
  if (coordinateY[i] == '.' && !(isdigit(coordinateY[i + 1])))
    coordinates.flag_y = 0;

  for (i = 0; i < strlen(coordinateX); i++)
  {
    if (isdigit(coordinateX[i]) &&
        (!(isdigit(coordinateX[i + 1])) && coordinateX[i + 1] != '.') &&
        isdigit(coordinateX[i + 2]))
      coordinates.flag_x = 0;
  }

  for (i = 0; i < strlen(coordinateY); i++)
  {
    if (isdigit(coordinateY[i]) &&
        (!(isdigit(coordinateY[i + 1])) && coordinateY[i + 1] != '.') &&
        isdigit(coordinateY[i + 2]))
      coordinates.flag_y = 0;
  }

  for (i = 0; i < strlen(radius); i++)
  {
    if (isdigit(radius[i]) &&
        (!(isdigit(radius[i + 1])) && radius[i + 1] != '.') &&
        isdigit(radius[i + 2]))
      coordinates.flag_radius = 0;
  }

  coordinates.x = atof(coordinateX);
  coordinates.y = atof(coordinateY);
  coordinates.radius = atof(radius);

  return coordinates;
}
void _check_coordinates(Circle *coordinates)
{
  if (coordinates->x == _INVALID_VALUE)
    coordinates->flag_x = 0;
  if (coordinates->y == _INVALID_VALUE)
    coordinates->flag_y = 0;
  if (coordinates->radius == _INVALID_VALUE)
    coordinates->flag_radius = 0;

  return;
}
