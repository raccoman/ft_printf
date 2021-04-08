#ifndef UTILS_H
# define UTILS_H

# include <wchar.h>
# include <stdlib.h>

# define TRUE 1
# define FALSE 0
# define INT128 __int128_t
# define UINT128 __uint128_t
# define P_VALUE format.precision.value
# define IS_PRECISION format.precision.present
# define W_VALUE format.width.value
# define IS_WIDTH format.width.present
# define IS_MINUS format.flags[MINUS]
# define IS_PLUS format.flags[PLUS]
# define IS_SPACE format.flags[SPACE]
# define IS_ZERO format.flags[ZERO]
# define IS_SHARP format.flags[SHARP]
# define NAN_INF(x) (ft_isnan(x) || ft_isinf(x))
# define ABS(x) x < 0 ? -x : x
# define MAX(a, b)		((b & ((a - b) >> 31)) | (a & (~(a - b) >> 31)))
# define MIN(a, b)		((a & ((a - b) >> 31)) | (b & (~(a - b) >> 31)))

int				ft_uatoi(char **input);

char			*ft_ftoe(double value, int sharp, int precision, int upcase);

int				ft_is_digit(int c);

size_t			ft_strlen(const char *string);

int				ft_round(UINT128 part, double value, int precision);

size_t			ft_strclen(const char *string, int c);

size_t			ft_wstrlen(const wchar_t *string);

char			*ft_itoa_base(UINT128 nb, int base_num, int upcase);

char			*ft_tohexa(__uint128_t n);

void			*ft_calloc(size_t count, size_t size);

void			*ft_memset(void *b, int c, size_t n);

char			*ft_strdup(const char *s1);

char			*ft_strndup(const char *s1, size_t length);

void			*ft_memcpy(void *dst, const void *src, size_t n);

int				ft_isnan(double x);

int				ft_isinf(double x);

char			*ft_ftoa(long double value, int precision, int upcase);

void			*ft_realloc(void *src, size_t length, size_t new_size);

long double		ft_power(long nb, int power);

void			ft_prepare_wchar(int *count, wchar_t c);

int				ft_isnegative(double value);

#endif
