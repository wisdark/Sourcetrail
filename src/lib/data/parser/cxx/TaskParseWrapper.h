#ifndef TASK_PARSE_WRAPPER_H
#define TASK_PARSE_WRAPPER_H

#include <memory>

#include "data/parser/Parser.h"
#include "data/parser/ParserClientImpl.h"
#include "utility/scheduling/TaskDecorator.h"
#include "utility/TimePoint.h"

class PersistentStorage;
class FileRegister;

class TaskParseWrapper
	: public TaskDecorator
{
public:
	TaskParseWrapper(
		PersistentStorage* storage,
		std::shared_ptr<FileRegister> fileRegister
	);
	virtual ~TaskParseWrapper();

	virtual void enter();
	virtual TaskState update();
	virtual void exit();

	virtual void interrupt();
	virtual void revert();

private:
	PersistentStorage* m_storage;
	std::shared_ptr<FileRegister> m_fileRegister;
	TimePoint m_start;
};

#endif // TASK_PARSE_WRAPPER_H
