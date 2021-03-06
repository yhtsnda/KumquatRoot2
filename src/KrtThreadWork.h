#pragma once

#include "wx/wx.h"
#include "wx/app.h"
#include "wx/dir.h"
#include "wx/regex.h"
#include "wx/timer.h"
#include "wx/ffile.h"
#include "wx/filefn.h"
#include "wx/thread.h"

//////////////////////////////////////////////////////////////////////////

class ThreadWork: public wxThread
{
public:
	ThreadWork(
		const wxArrayString &,
		wxString &,
		unsigned long &,
		unsigned long &,
		wxArrayString &,
		wxWindow *,
		bool &
	);
	virtual void *Entry();

private:
	const wxArrayString &parItems;
	wxString &current;
	unsigned long &lTotal;
	unsigned long &lFit;
	wxArrayString &resultItems;
	wxWindow	*wnd;
	bool &threadstop;

	//读取文件内容
	void readFileData( wxString &, wxString & );	//读取文件内容

	//检索入口
	bool MatchTheFile( wxString & );

	//按条件检索
	bool matchFileName( wxString & );				//普通匹配文件名
	bool regexMatchFileName( wxString & );			//正则方式匹配文件名

	bool matchFileCont( wxString & );				//普通方式匹配文件内容
	bool regexMatchFileCont( wxString & );			//正则方式匹配文件内容

	//...

	bool unfitExtendName( wxString & );			//仅过滤以上扩展名
	bool fitExtendName( wxString & );			//仅搜索扩展名
};
