using std::vector;

/**
 *  @brief  Initializes %std::vector as a set of random values. 
 *  @param  data  The initialized %std::vector.
 */
template <typename T>
void set_random(vector<T>& data)
{
    vector<T> vect;
    T subdata;
    for (int i = 0; i < RANDOM_VECTOR_SIZE; i++)
    {
        set_random(subdata);
        vect.push_back(subdata);
    }
    data = vect;
}

/**
 *  @brief  Returns a random value for any supported type.
 */
template <typename T>
T get_random()
{
    T data;
    set_random(data);
    return data;
}
