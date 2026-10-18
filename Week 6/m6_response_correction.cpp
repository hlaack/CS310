#include <iostream>
#include <typeinfo>
using namespace std;

enum class scoped_days {MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY};
enum unscoped_days {MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY};

int main()
{

    // SCOPED USAGE

    scoped_days scoped_today = scoped_days::MONDAY;

    int integer_today = static_cast<int>(scoped_today);

    integer_today++;

    integer_today = integer_today + 2;

    scoped_today = static_cast<scoped_days>(integer_today);

    cout << static_cast<underlying_type<scoped_days>::type>(scoped_today) << endl;

    // UNSCOPED USAGE

    int unscoped_today = MONDAY;

    unscoped_today++;

    unscoped_today = unscoped_today + 2;

    cout << unscoped_today << endl;

    // End of program.

    cout << "Program finished." << endl;

    return 0;

}
