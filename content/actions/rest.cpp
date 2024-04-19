#include "rest.h"
#include <iostream>

Result Rest::perform(Engine&, std::shared_ptr<Entity>) {
    return success();
}
