class MyClass
{
	void testSigned(signed char c)
	{
	}
	void testUnsigned(unsigned char c)
	{
	}
	void test(char c)
	{
		testSigned(c);
		testUnsigned(c);
	}
	void test()
	{
		test(-1);
	}
};
