#pragma once

// error handling class
class MyException
{
public:
	int m_nErrorNo;
	String m_strReason;
};

void func()
{
	// do something...
	if (error_occurred) {
		MyException e;
		e.m_nErrorNo = 10;
		e.m_strReason = "Critical";
		throw e;
	}
}

void other_func()
{
	try {
		func();
	}
	catch (MyException e) {
		// error process
	}
	catch (...) { // 위에서 걸리지 않은 에러 (...), 여기서 받아준다
				  // other error;
	}
}