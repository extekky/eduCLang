
#ifndef MYSTRING_H
#define MYSTRING_H

/**
 * @brief Извлекает срез из строки.
 *
 * Эта функция создает новый строковый массив, который содержит символы
 * из исходной строки, начиная с индекса `begin`, заканчивая индексом `end`
 * (не включая его), и с заданным шагом `step`.
 *
 * @param string Указатель на исходную строку, из которой будет извлекаться
 * срез.
 * @param begin Индекс, с которого начинается извлечение (включительно).
 * @param end Индекс, на котором заканчивается извлечение (не включая).
 * @param step Шаг, с которым будут извлекаться символы из строки.
 * @return Указатель на новый строковый массив, содержащий срез.
 *         Если `begin` или `end` выходят за пределы строки,
 *         или если `step` равен 0, функция возвращает NULL.
 */
char *sliceString(char *string, long int begin, long int end, long int step);
char *reverseString(const char *s);
char *longestPalindrome(char *s);

#endif