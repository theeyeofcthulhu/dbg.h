#ifdef __cplusplus

// Preevaluate the expression so that none of the
// expression's possible outputs break up the DBG
// string
#define DBG(x) do { \
    auto x2 = (x); \
    std::cout << #x << ": " << x2 << '\n'; \
} while (0)

#define HERE std::cout << "here\n"
#define MSG(x) std::cout << (x) << '\n'

#else

/* Turns the type of x into a format string.
 * If you want to debug the value of a char *,
 * as opposed to a string it points to, cast
 * the char * to some other pointer type.*/

#define DBG_FMT(x) _Generic((x), \
                        short:              "%s: %hd\n", \
                        unsigned short:     "%s: %hu\n", \
                        int:                "%s: %d\n", \
                        unsigned int:       "%s: %u\n", \
                        long:               "%s: %ld\n", \
                        unsigned long:      "%s: %lu\n", \
                        long long:          "%s: %lld\n", \
                        unsigned long long: "%s: %llu\n", \
                        double:             "%s: %f\n", \
                        long double:        "%s: %Lf\n", \
                        float:              "%s: %f\n", \
                        char:               "%s: %c\n", \
                        unsigned char:      "%s: %c\n", \
                        const char *:       "%s: %s\n", \
                        char *:             "%s: %s\n", \
                        default:            "%s: %p\n" \
                        )

/* Apparently, const char * needs to be specified, 
   otherwise DBG(const char *) will
   go to default case. */

#define DBG(x) printf(DBG_FMT(x), #x, (x))

/* Associate types with printer functions here.
 * E.g: vector: print_vec \ */
#define TG_PRINT_USER_DEFINED_TYPE(x) _Generic((x), \
                        )(x)

#define UDBG(x) do { \
                    printf("%s: ", #x); \
                    TG_PRINT_USER_DEFINED_TYPE(x); \
                    printf("\n"); \
                } while(0)

#define HERE() puts("here")
#define MSG(x) puts((x))

#endif // __cplusplus

/* some optional shorthands (won't be defined
 * if the letters are already in use by the
 * preprocessor) */

#ifndef D
#define D DBG
#endif

#ifndef H
#define H HERE
#endif

#ifndef M
#define M MSG
#endif
