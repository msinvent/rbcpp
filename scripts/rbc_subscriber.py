from scripts.generator import Generator


class RBCSubscriber(Generator):
    def __init__(self, params: dict):
        super().__init__(['class_name', 'type', 'guard', 'header_name', 'ros_msg_type', 'ros_msg_name', 'ros_msg_name_lower'])
        self.header_template_name = 'templates/header_subscriber.tmpl'
        self.impl_template_name = 'templates/impl_subscriber.tmpl'
        self.param_dict = params
        self.param_dict['ros_msg_name_lower'] = params.get('ros_msg_name').lower()

    def create(self):
        print("Creating files for class {}".format(self.param_dict.get('class_name')))
        super().read(self.header_template_name, self.impl_template_name)
        super().write(self.param_dict)
