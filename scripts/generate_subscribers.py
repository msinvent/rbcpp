from scripts.rbc_subscriber import RBCSubscriber

if __name__ == '__main__':
    d = {}
    d['class_name'] = 'RBCStringSubscriber'
    d['type'] = 'std_msgs::StringMessage'
    d['ros_msg_type'] = 'std_msgs'
    d['ros_msg_name'] = 'String'

    message = RBCSubscriber(d)
    message.create()

    d['class_name'] = 'RBCAccelSubscriber'
    d['type'] = 'geometry_msgs::AccelMessage'
    d['ros_msg_type'] = 'geometry_msgs'
    d['ros_msg_name'] = 'Accel'

    message = RBCSubscriber(d)
    message.create()