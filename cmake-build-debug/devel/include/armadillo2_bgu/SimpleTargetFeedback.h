// Generated by gencpp from file armadillo2_bgu/SimpleTargetFeedback.msg
// DO NOT EDIT!


#ifndef ARMADILLO2_BGU_MESSAGE_SIMPLETARGETFEEDBACK_H
#define ARMADILLO2_BGU_MESSAGE_SIMPLETARGETFEEDBACK_H


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
struct SimpleTargetFeedback_
{
  typedef SimpleTargetFeedback_<ContainerAllocator> Type;

  SimpleTargetFeedback_()
    : x(0.0)
    , y(0.0)
    , z(0.0)
    , distance(0.0)  {
    }
  SimpleTargetFeedback_(const ContainerAllocator& _alloc)
    : x(0.0)
    , y(0.0)
    , z(0.0)
    , distance(0.0)  {
  (void)_alloc;
    }



   typedef float _x_type;
  _x_type x;

   typedef float _y_type;
  _y_type y;

   typedef float _z_type;
  _z_type z;

   typedef float _distance_type;
  _distance_type distance;





  typedef boost::shared_ptr< ::armadillo2_bgu::SimpleTargetFeedback_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::armadillo2_bgu::SimpleTargetFeedback_<ContainerAllocator> const> ConstPtr;

}; // struct SimpleTargetFeedback_

typedef ::armadillo2_bgu::SimpleTargetFeedback_<std::allocator<void> > SimpleTargetFeedback;

typedef boost::shared_ptr< ::armadillo2_bgu::SimpleTargetFeedback > SimpleTargetFeedbackPtr;
typedef boost::shared_ptr< ::armadillo2_bgu::SimpleTargetFeedback const> SimpleTargetFeedbackConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::armadillo2_bgu::SimpleTargetFeedback_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::armadillo2_bgu::SimpleTargetFeedback_<ContainerAllocator> >::stream(s, "", v);
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
struct IsFixedSize< ::armadillo2_bgu::SimpleTargetFeedback_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::armadillo2_bgu::SimpleTargetFeedback_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::armadillo2_bgu::SimpleTargetFeedback_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::armadillo2_bgu::SimpleTargetFeedback_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::armadillo2_bgu::SimpleTargetFeedback_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::armadillo2_bgu::SimpleTargetFeedback_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::armadillo2_bgu::SimpleTargetFeedback_<ContainerAllocator> >
{
  static const char* value()
  {
    return "69d34abcf3fe71001b097f13b8b8c24f";
  }

  static const char* value(const ::armadillo2_bgu::SimpleTargetFeedback_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x69d34abcf3fe7100ULL;
  static const uint64_t static_value2 = 0x1b097f13b8b8c24fULL;
};

template<class ContainerAllocator>
struct DataType< ::armadillo2_bgu::SimpleTargetFeedback_<ContainerAllocator> >
{
  static const char* value()
  {
    return "armadillo2_bgu/SimpleTargetFeedback";
  }

  static const char* value(const ::armadillo2_bgu::SimpleTargetFeedback_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::armadillo2_bgu::SimpleTargetFeedback_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======\n\
# The internal state that the pickup action currently is in\n\
\n\
float32 x\n\
float32 y\n\
float32 z\n\
float32 distance\n\
";
  }

  static const char* value(const ::armadillo2_bgu::SimpleTargetFeedback_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::armadillo2_bgu::SimpleTargetFeedback_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.x);
      stream.next(m.y);
      stream.next(m.z);
      stream.next(m.distance);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct SimpleTargetFeedback_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::armadillo2_bgu::SimpleTargetFeedback_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::armadillo2_bgu::SimpleTargetFeedback_<ContainerAllocator>& v)
  {
    s << indent << "x: ";
    Printer<float>::stream(s, indent + "  ", v.x);
    s << indent << "y: ";
    Printer<float>::stream(s, indent + "  ", v.y);
    s << indent << "z: ";
    Printer<float>::stream(s, indent + "  ", v.z);
    s << indent << "distance: ";
    Printer<float>::stream(s, indent + "  ", v.distance);
  }
};

} // namespace message_operations
} // namespace ros

#endif // ARMADILLO2_BGU_MESSAGE_SIMPLETARGETFEEDBACK_H