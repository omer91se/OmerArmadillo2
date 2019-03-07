// Generated by gencpp from file armadillo2_bgu/ReturnJointStatesRequest.msg
// DO NOT EDIT!


#ifndef ARMADILLO2_BGU_MESSAGE_RETURNJOINTSTATESREQUEST_H
#define ARMADILLO2_BGU_MESSAGE_RETURNJOINTSTATESREQUEST_H


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
struct ReturnJointStatesRequest_
{
  typedef ReturnJointStatesRequest_<ContainerAllocator> Type;

  ReturnJointStatesRequest_()
    : name()  {
    }
  ReturnJointStatesRequest_(const ContainerAllocator& _alloc)
    : name(_alloc)  {
  (void)_alloc;
    }



   typedef std::vector<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > , typename ContainerAllocator::template rebind<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::other >  _name_type;
  _name_type name;





  typedef boost::shared_ptr< ::armadillo2_bgu::ReturnJointStatesRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::armadillo2_bgu::ReturnJointStatesRequest_<ContainerAllocator> const> ConstPtr;

}; // struct ReturnJointStatesRequest_

typedef ::armadillo2_bgu::ReturnJointStatesRequest_<std::allocator<void> > ReturnJointStatesRequest;

typedef boost::shared_ptr< ::armadillo2_bgu::ReturnJointStatesRequest > ReturnJointStatesRequestPtr;
typedef boost::shared_ptr< ::armadillo2_bgu::ReturnJointStatesRequest const> ReturnJointStatesRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::armadillo2_bgu::ReturnJointStatesRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::armadillo2_bgu::ReturnJointStatesRequest_<ContainerAllocator> >::stream(s, "", v);
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
struct IsFixedSize< ::armadillo2_bgu::ReturnJointStatesRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::armadillo2_bgu::ReturnJointStatesRequest_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::armadillo2_bgu::ReturnJointStatesRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::armadillo2_bgu::ReturnJointStatesRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::armadillo2_bgu::ReturnJointStatesRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::armadillo2_bgu::ReturnJointStatesRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::armadillo2_bgu::ReturnJointStatesRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "3f2d21c30868b92dc41a0431bacd47b2";
  }

  static const char* value(const ::armadillo2_bgu::ReturnJointStatesRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x3f2d21c30868b92dULL;
  static const uint64_t static_value2 = 0xc41a0431bacd47b2ULL;
};

template<class ContainerAllocator>
struct DataType< ::armadillo2_bgu::ReturnJointStatesRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "armadillo2_bgu/ReturnJointStatesRequest";
  }

  static const char* value(const ::armadillo2_bgu::ReturnJointStatesRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::armadillo2_bgu::ReturnJointStatesRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "string[] name\n\
";
  }

  static const char* value(const ::armadillo2_bgu::ReturnJointStatesRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::armadillo2_bgu::ReturnJointStatesRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.name);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct ReturnJointStatesRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::armadillo2_bgu::ReturnJointStatesRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::armadillo2_bgu::ReturnJointStatesRequest_<ContainerAllocator>& v)
  {
    s << indent << "name[]" << std::endl;
    for (size_t i = 0; i < v.name.size(); ++i)
    {
      s << indent << "  name[" << i << "]: ";
      Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.name[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // ARMADILLO2_BGU_MESSAGE_RETURNJOINTSTATESREQUEST_H