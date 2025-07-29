#include vulkan.h

VkXXXCreateInfo createInfo{}; // struct == StartCamelCase

createInfo.sType = VK_STRUCTURE_TYPE_XXX_CREATE_INFO;
createInfo.pNext = nullptr;

VkXXX object;
if (vkCreateXXX(&createInfo, nullptr, &object) != VK_SUCCESS) { // func camelCase, enum SNAKE_CASE
    std::cerr << "failed to create object" << std::endl;
    return false;
}
