
void    print_square(size_t size, char fill) {
    for (size_t i = 0 ; i < size ; i ++) {
        for (size_t j = 0 ; j < size ; j ++) {
            write(1, &fill, 1);
        }
        write(1,"\n", 1);
    }
}