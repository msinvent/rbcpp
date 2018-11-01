from scripts.generator import Generator
from scripts.generator import Converter


class ArrayRBCMessage(Generator):
    def __init__(self, params: dict):
        super().__init__(['class_name', 'inher', 'guard', 'header_name', 'ros_msg_type', 'ros_msg_name',
                          'array_ros_type', 'array_ros_type_lower', 'array_descriptor'])
        self.header_template_name = 'templates/header_array.tmpl'
        self.impl_template_name = 'templates/impl_array.tmpl'
        self.param_dict = params
        self.param_dict['array_ros_type_lower'] = Converter.to_lower(d.get('array_ros_type'))

    def create(self):
        print("Creating files for class {}".format(self.param_dict.get('class_name')))
        super().read(self.header_template_name, self.impl_template_name)
        super().write(self.param_dict)


if __name__ == '__main__':
    d = {}
    d['class_name'] = 'PolygonMessage'
    d['ros_msg_type'] = 'geometry_msgs'
    d['ros_msg_name'] = 'Polygon'
    d['array_ros_type'] = 'Point'
    d['inher'] = 'override'
    d['array_descriptor'] = 'points'

    message = ArrayRBCMessage(d)
    message.create()