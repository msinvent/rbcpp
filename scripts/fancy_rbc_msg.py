from scripts.generator import Generator
from scripts.generator import Converter


class FancyRBCMessage(Generator):
    def __init__(self, params: dict):
        super().__init__(['class_name', 'base_class', 'guard', 'header_name', 'base_class_header_name','ros_msg_type', 'ros_msg_name'])
        self.header_template_name = 'templates/header_fancy.tmpl'
        self.impl_template_name = 'templates/impl_fancy.tmpl'
        self.param_dict = params
        self.param_dict['base_class_header_name'] = Converter.camel_to_snake(d.get('base_class'))

    def create(self):
        print("Creating files for class {}".format(self.param_dict.get('class_name')))
        super().read(self.header_template_name, self.impl_template_name)
        super().write(self.param_dict)


if __name__ == '__main__':
    d = {}
    d['class_name'] = 'InertiaStampedMessage'
    d['base_class'] = 'InertiaMessage'
    d['ros_msg_type'] = 'geometry_msgs'
    d['ros_msg_name'] = 'InertiaStamped'

    message = FancyRBCMessage(d)
    message.create()