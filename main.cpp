#include <iostream>
#include <ostream>
#include <stdexcept>

namespace topit
{
  struct p_t
  {
    int x, y;
  };
  bool operator==(p_t, p_t);
  bool operator!=(p_t, p_t);
  struct f_t
  {
    p_t aa, bb;
  };
  struct IDraw
  {
    virtual ~IDraw() = default;
    virtual p_t begin() const = 0;
    virtual p_t next(p_t) const = 0;
  };
  struct Dot: IDraw
  {
    Dot(int x, int y);
    explicit Dot(p_t dd);
    p_t begin() const override;
    p_t next(p_t) const override;
    p_t d;
  };
  struct HLine: IDraw
  {
    HLine(int x, int y, int length);

    p_t begin() const override;
    p_t next(p_t) const override;

    p_t start;
    int len;
  };
  size_t points(const IDraw& d, p_t** pts, size_t s);
  f_t frame(const p_t* pts, size_t s);
  char* canvas(f_t fr, char fill);
  void paint(char* cnv, f_t fr, p_t p, char fill);
  void flush(std::ostream& os, const char* cnv, f_t fr);
}

int main()
{
  using namespace topit;
  int err = 0;
  IDraw* shps[3] = {};
  p_t* pts = nullptr;
  size_t s = 0;
  try
  {
    shps[0] = new Dot(0, 0);
    shps[1] = new Dot(5, 7);
    shps[2] = new HLine(0, 3, 6);  
    for (size_t i = 0; i < 3; ++i)
    {
      s += points(*(shps[i]), &pts, s);
    }
    f_t fr = frame(pts, s);
    char* cnv = canvas(fr, '.');
    for (size_t i = 0; i < s; ++i)
    {
      paint(cnv, fr, pts[i], '#');
    }
    flush(std::cout, cnv, fr);
    delete[] cnv;
  }
  catch (...)
  {
    err = 2;
    std::cerr << "Bad drawing\n";
  }

  delete shps[0];
  delete shps[1];
  delete shps[2];
  delete[] pts;
  return err;
}

topit::Dot::Dot(p_t dd):
  IDraw(),
  d{dd}
{}
topit::Dot::Dot(int x, int y):
  IDraw(),
  d{x, y}
{}
topit::p_t topit::Dot::begin() const
{
  return d;
}
topit::p_t topit::Dot::next(p_t prev) const
{
  if (prev != begin())
  {
    throw std::logic_error("bad impl");
  }
  return d;
}
topit::HLine::HLine(int x, int y, int length):
  IDraw(),
  start{x, y},
  len{length}
{}
topit::p_t topit::HLine::begin() const
{
  return start;
}
bool topit::operator==(p_t a, p_t b)
{
  return a.x == b.x && a.y == b.y;
}
bool topit::operator!=(p_t a, p_t b)
{
  return !(a == b);
}
topit::p_t topit::HLine::next(p_t prev) const
{
  if (prev.x < start.x + len - 1)
  {
    return p_t{prev.x + 1, prev.y};
  }
  return prev; 
}
size_t topit::points(const IDraw& d, p_t** pts, size_t s)
{
  // TODO
  return 0;
}
topit::f_t topit::frame(const p_t* pts, size_t s)
{
  // TODO
  return f_t{{0, 0}, {0, 0}};
}
char* topit::canvas(f_t fr, char fill)
{
  // TODO
  return nullptr;
}
void topit::paint(char* cnv, f_t fr, p_t p, char fill)
{
  // TODO
}
void topit::flush(std::ostream& os, const char* cnv, f_t fr)
{
  // TODO
}
