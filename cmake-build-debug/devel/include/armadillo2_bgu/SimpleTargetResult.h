// Generated by gencpp from file armadillo2_bgu/SimpleTargetResult.msg
// DO NOT EDIT!


#ifndef ARMADILLO2_BGU_MESSAGE_SIMPLETARGETRESULT_H
#define ARMADILLO2_BGU_MESSAGE_SIMPLETARGETRESULT_H


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
struct SimpleTargetResult_
{
  typedef SimpleTargetResult_<ContainerAllocator> Type;

  SimpleTargetResult_()
    : x(0.0)
    , y(0.0)
    , z(0.0)  {
    }
  SimpleTargetResult_(const ContainerAllocator& _alloc)
    : x(0.0)
    , y(0.0)
    , z(0.0)  {
  (void)_alloc;
    }



   typedef float _x_type;
  _x_type x;

   typedef float _y_type;
  _y_type y;

   typedef float _z_type;
  _z_type z;





  typedef boost::shared_ptr< ::armadillo2_bgu::SimpleTargetResult_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::armadillo2_bgu::SimpleTargetResult_<ContainerAllocator> const> ConstPtr;

}; // struct SimpleTargetResult_

typedef ::armadillo2_bgu::SimpleTargetResult_<std::allocator<void> > SimpleTargetResult;

typedef boost::shared_ptr< ::armadillo2_bgu::SimpleTargetResult > SimpleTargetResultPtr;
typedef boost::shared_ptr< ::armadillo2_bgu::SimpleTargetResult const> SimpleTargetResultConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::armadillo2_bgu::SimpleTargetResult_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::armadillo2_bgu::SimpleTargetResult_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace armadillo2_bgu

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'armadillo2_bgu': ['/home/labkinetic/catkin_ws/src/Planning/msg', '/home/labkinetic/catkin_ws/src/Planning/cmake-build-debug/devel/share/armadillo2_bgu/msg'], 'actionlib_msgs': ['/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg'], 'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::armadillo2_bgu::SimpleTargetResult_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::armadillo2_bgu::SimpleTargetResult_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::armadillo2_bgu::SimpleTargetResult_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::armadillo2_bgu::SimpleTargetResult_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::armadillo2_bgu::SimpleTargetResult_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::armadillo2_bgu::SimpleTargetResult_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::armadillo2_bgu::SimpleTargetResult_<ContainerAllocator> >
{
  static const char* value()
  {
    return "cc153912f1453b708d221682bc23d9ac";
  }

  static const char* value(const ::armadillo2_bgu::SimpleTargetResult_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xcc153912f1453b70ULL;
  static const uint64_t static_value2 = 0x8d221682bc23d9acULL;
};

template<class ContainerAllocator>
struct DataType< ::armadillo2_bgu::SimpleTargetResult_<ContainerAllocator> >
{
  static const char* value()
  {
    return "armadillo2_bgu/SimpleTargetResult";
  }

  static const char* value(const ::armadillo2_bgu::SimpleTargetResult_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::armadillo2_bgu::SimpleTargetResult_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======\n\
# Define the result\n\
\n\
float32 x\n\
float32 y\n\
float32 z\n\
\n\
";
  }

  static const char* value(const ::armadillo2_bgu::SimpleTargetResult_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::armadillo2_bgu::SimpleTargetResult_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.x);
      stream.next(m.y);
      stream.next(m.z);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct SimpleTargetResult_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::armadillo2_bgu::SimpleTargetResult_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::armadillo2_bgu::SimpleTargetResult_<ContainerAllocator>& v)
  {
    s << indent << "x: ";
    Printer<float>::stream(s, indent + "  ", v.x);
    s << indent << "y: ";
    Printer<float>::stream(s, indent + "  ", v.y);
    s << indent << "z: ";
    Printer<float>::stream(s, indent + "  ", v.z);
  }
};

} // namespace message_operations
} // namespace ros

#endif // ARMADILLO2_BGU_MESSAGE_SIMPLETARGETRESULT_H