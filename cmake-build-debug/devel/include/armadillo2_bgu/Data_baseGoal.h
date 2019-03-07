// Generated by gencpp from file armadillo2_bgu/Data_baseGoal.msg
// DO NOT EDIT!


#ifndef ARMADILLO2_BGU_MESSAGE_DATA_BASEGOAL_H
#define ARMADILLO2_BGU_MESSAGE_DATA_BASEGOAL_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace armadillo2_bgu
{
template <class ContainerAllocator>
struct Data_baseGoal_
{
  typedef Data_baseGoal_<ContainerAllocator> Type;

  Data_baseGoal_()
    : key()
    , x(0.0)
    , y(0.0)
    , z(0.0)  {
    }
  Data_baseGoal_(const ContainerAllocator& _alloc)
    : key(_alloc)
    , x(0.0)
    , y(0.0)
    , z(0.0)  {
  (void)_alloc;
    }



   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _key_type;
  _key_type key;

   typedef double _x_type;
  _x_type x;

   typedef double _y_type;
  _y_type y;

   typedef double _z_type;
  _z_type z;





  typedef boost::shared_ptr< ::armadillo2_bgu::Data_baseGoal_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::armadillo2_bgu::Data_baseGoal_<ContainerAllocator> const> ConstPtr;

}; // struct Data_baseGoal_

typedef ::armadillo2_bgu::Data_baseGoal_<std::allocator<void> > Data_baseGoal;

typedef boost::shared_ptr< ::armadillo2_bgu::Data_baseGoal > Data_baseGoalPtr;
typedef boost::shared_ptr< ::armadillo2_bgu::Data_baseGoal const> Data_baseGoalConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::armadillo2_bgu::Data_baseGoal_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::armadillo2_bgu::Data_baseGoal_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace armadillo2_bgu

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': False}
// {'armadillo2_bgu': ['/home/labkinetic/catkin_ws/src/Planning/msg', '/home/labkinetic/catkin_ws/src/Planning/cmake-build-debug/devel/share/armadillo2_bgu/msg'], 'actionlib_msgs': ['/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg'], 'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::armadillo2_bgu::Data_baseGoal_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::armadillo2_bgu::Data_baseGoal_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::armadillo2_bgu::Data_baseGoal_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::armadillo2_bgu::Data_baseGoal_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::armadillo2_bgu::Data_baseGoal_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::armadillo2_bgu::Data_baseGoal_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::armadillo2_bgu::Data_baseGoal_<ContainerAllocator> >
{
  static const char* value()
  {
    return "bc057794dbb852021a703d1755817da5";
  }

  static const char* value(const ::armadillo2_bgu::Data_baseGoal_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xbc057794dbb85202ULL;
  static const uint64_t static_value2 = 0x1a703d1755817da5ULL;
};

template<class ContainerAllocator>
struct DataType< ::armadillo2_bgu::Data_baseGoal_<ContainerAllocator> >
{
  static const char* value()
  {
    return "armadillo2_bgu/Data_baseGoal";
  }

  static const char* value(const ::armadillo2_bgu::Data_baseGoal_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::armadillo2_bgu::Data_baseGoal_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======\n\
# Define the goal\n\
string key  \n\
float64 x\n\
float64 y\n\
float64 z\n\
";
  }

  static const char* value(const ::armadillo2_bgu::Data_baseGoal_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::armadillo2_bgu::Data_baseGoal_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.key);
      stream.next(m.x);
      stream.next(m.y);
      stream.next(m.z);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct Data_baseGoal_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::armadillo2_bgu::Data_baseGoal_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::armadillo2_bgu::Data_baseGoal_<ContainerAllocator>& v)
  {
    s << indent << "key: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.key);
    s << indent << "x: ";
    Printer<double>::stream(s, indent + "  ", v.x);
    s << indent << "y: ";
    Printer<double>::stream(s, indent + "  ", v.y);
    s << indent << "z: ";
    Printer<double>::stream(s, indent + "  ", v.z);
  }
};

} // namespace message_operations
} // namespace ros

#endif // ARMADILLO2_BGU_MESSAGE_DATA_BASEGOAL_H
