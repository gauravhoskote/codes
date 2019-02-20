#include "boost/gil.hpp"

using namespace std;
using namespace boost::gil;

void simplethreshold(const gray8c_view_t& src, const gray8s_view_t& dst, int thresh){
  gray8c_view_t::xy_locator src_loc = src.xy_at(0,0);
  for (int y=0; y<src.height(); y++)
  {
      gray8s_view_t::x_iterator dst_it  = dst.row_begin(y);
      for (int x=0; x<src.width(); x++)
      {
        if(src_loc(0,0) < thresh){
            (*dst_it) = 0;
        }
        else{
        	(*dst_it) = 255;
        }
        ++dst_it;
        ++src_loc.x();
      }
      src_loc+=point<std::ptrdiff_t>(-src.width(),1);
  }
}





