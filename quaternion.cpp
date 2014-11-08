class Quaterion {
    public:
        Quaternion();
        Quaternion(float re);
        Quaternion(float re, float im);
        Quaternion(float a, float b, float c, float d);
        Quaternion(Quaternion s1); 
        // operators
    private:
        float re, i, j, k;

}

Quaternion::Quaternion() {
    // bla bla
}
