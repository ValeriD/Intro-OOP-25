#include <iostream>

using namespace std;

class Parking
{
    // Add fields:
    // Number of total spots to stop
    // Number of taken spots

public:
    /**
     * @brief Construct a new empty Parking object - 0 spots, 0 taken
     *
     */
    Parking();

    /**
     * @brief Construct a new Parking object with total spots and 0 takne
     *
     * @param totalSpots
     */
    Parking(int totalSpots);

    /**
     * @brief Construct a new Parking object with total spots and taken spots
     *
     * @param totalSpots
     * @param takenSpots
     */
    Parking(int totalSpots, int takenSpots);

    /**
     * @brief Takes one spot
     *
     */
    void takeSpot();

    /**
     * @brief Frees one spot
     *
     */
    void freeSpot();

    /**
     * @brief Get the total free spots in the parking lot
     *
     */
    int getTotalFreeSpots() const;
};

int main()
{

    // Demonstrate the Parking class with all functionalities
    return 0;
}
