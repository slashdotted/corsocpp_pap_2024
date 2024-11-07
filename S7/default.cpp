class Example {
public:
    Example(int i)
    {
    }
    Example() = default; // Trivial constructor
    // Trivially constructible types can be safely copied into and from an array of bytes (for example char)
};

int main()
{
    Example e;
}
