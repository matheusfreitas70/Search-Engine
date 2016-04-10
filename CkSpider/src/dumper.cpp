#include "dumper.hpp"
using namespace std;

Dumper::Dumper()
{}

void Dumper::SetFilename(string filename)
{
  this->_filename = filename;
}

void Dumper::OpenStream()
{
  this->_fb.open(this->_filename, ios::out);
}

void Dumper::Dump()
{
  if(this->_vp.size() > 10000) this->ForceDump();
}

void Dumper::ForceDump()
{
  for(unsigned i = 0; i < this->_vp.size(); i++)
  {
    ostream out(&this->_fb);
    out << this->_vp[i].GetUrl() << endl;
    out << this->_vp[i].GetHtml() << endl << endl;
    out << "|||\n\n";
  }
  this->_vp.clear();
}

void Dumper::AddPage(string url, string title, string html)
{
  Page p(url, title, html);
  this->_vp.push_back(p);
}

void Dumper::CloseStream()
{
  this->_fb.close();
}