#include <iostream>
namespace topit{
  struct p_t {
    int x, y;
  };
  bool operator==(p_t, p_t);
  bool operator!=(p_t, p_t);
  struct f_t {
    p_t aa, bb;
  };
  struct IDraw{
    virtual ~IDraw() = default;
    virtual p_t begin() const = 0;
    virtual p_t next(p_t) const = 0;
  };
  struct Dot: IDraw{
    Dot(int x, int y);
    explicit Dot(p_t dd)
    p_t begin() const override;
    p_t next(p_t) const override;
    p_t d;
    size_t points(const IDraw& d, p_t** pts, size_t s);
    f_t frame(const p_t* pts, size_t s);
    char * canvas(f_t fr, chat fill);
    void paint(char * cnv, f_t fr, p_t p, char fill);

  };
}

int main()
{
  using topit::IDraw;
  using topit::Dot;
  using topit::f_t;
  int err = 0;
  p_t * pts = nullptr;
  IDraw* shps[3] = {};
  try {
    shps[0] = new Dot(0,0);
    shps[0] = new Dot(5,7);
    shps[0] = new Dot(-5,-2);
  // todo
  for (size_t i = 0; i < 3; ++i)
  {
    s += points(*(shps[i]), &pts, s);
  }
  f_t fr = frame(pts, s);
  char * cnv = canvas(fr, '.');
  fot (size_t i = 0; i < s; ++i)
  {
  paint(cnv, ft, pts[i], '#');
  }
//нарисовать полотно на экран
  delete [] cnv;
 } catch(...) {
    err = 2;
    std::cerr << "Bad drawing\n";
  }
  delete [] pts;
  delete shps[0];
  delete shps[1];
  delete shps[2];
  return err;
}
  topit::Dot::Dot(p_t dd):
    IDraw(),
    d{dd}
    {}

  topit::Dot::Dot(int x, int y):
    IDraw(),
    d{x,y}
    {}

  topit::p_t topit::Dot::begin() const {
    return d;
  }
  topit::p_t topit::Dot::next(p_t prev) const {
    if (prev != begin())
    {
      throw std::logic_error("bad impl");
    }
    return d;
  }
  bool topit::operator==(p_t a, p_t b){
    return a.x == b.x && a.y == b.y;
  }
  bool topit::operator!=(p_t a, p_t b){
    return !(a == b);
  }

    //IDraw * p = new Dot(10, 10);
  //IDraw * pp = new Dot(p_t(10, 10);

  //p_t a{1,0}, b{1,0};
  //std::cout << (a != b) << "\n";
