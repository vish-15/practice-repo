#ifndef DYNAMIC_CAREER_PATHS_H
#define DYNAMIC_CAREER_PATHS_H

#include <string>
#include <vector>

// Forward declarations
class Skill;
class Career;
class CareerPath;
class Specialization;
class Milestone;
class CareerEvent;
class JobApplication;

class Sim {
public:
    // Constructor
    Sim(const std::string& name, int age);

    // Methods
    void applyForJob(const Career& career);
    void advanceCareer();
    void developSkill(Skill& skill);
    void changeCareer(const Career& newCareer);

private:
    // Instance variables
    std::string name;
    int age;
    std::vector<std::string> traits;
    std::vector<Skill> skills;
    Career* currentCareer;  // Pointer to allow dynamic changes
};

class Career {
public:
    // Constructor
    Career(const std::string& jobTitle, float salary);

    // Methods
    void promote();
    void assignTask(const std::string& task);
    void setRequirements(const std::vector<Skill>& requirements);
    CareerPath* getCareerPath() const;

private:
    // Instance variables
    std::string jobTitle;
    float salary;
    std::vector<Skill> requiredSkills;
    std::vector<CareerPath> careerPathOptions;
};

class CareerPath {
public:
    // Constructor
    CareerPath(const std::string& pathName);

    // Methods
    void selectSpecialization(const Specialization& specialization);
    void completeMilestone(const Milestone& milestone);
    std::vector<CareerPath> getAvailablePaths() const;

private:
    // Instance variables
    std::string pathName;
    std::vector<Specialization> specializations;
    std::vector<Milestone> milestones;
};

class Skill {
public:
    // Constructor
    Skill(const std::string& skillName);

    // Methods
    void increaseLevel();
    std::vector<Career> getRelatedCareers() const;
    std::string displaySkillInfo() const;

private:
    // Instance variables
    std::string skillName;
    int skillLevel;
    std::vector<Career> relatedCareers;
};

class CareerEvent {
public:
    // Constructor
    CareerEvent(const std::string& eventName, const std::string& eventImpact);

    // Methods
    void triggerEvent();
    void applyEventImpact();
    std::string getEventDetails() const;

private:
    // Instance variables
    std::string eventName;
    std::string eventImpact;
    Career* relatedCareer;  // Pointer to allow dynamic linkage
};

class JobApplication {
public:
    // Constructor
    JobApplication(const Career& appliedJob, const Sim& applicant);

    // Methods
    void submitApplication();
    void updateStatus(const std::string& newStatus);
    std::string checkStatus() const;

private:
    // Instance variables
    std::string applicationStatus;
    const Career& appliedJob;  // Reference to ensure job is valid
    const Sim& applicant;      // Reference to ensure Sim is valid
    std::string applicationDate;
};

class Milestone {
public:
    // Constructor
    Milestone(const std::string& milestoneName);

    // Methods
    void achieveMilestone();
    std::string getMilestoneDetails() const;

private:
    // Instance variables
    std::string milestoneName;
    std::vector<Skill> milestoneRequirements;
    std::string milestoneRewards;
};

class Specialization {
public:
    // Constructor
    Specialization(const std::string& specializationName);

    // Methods
    void applySpecialization();
    std::string getSpecializationBenefits() const;

private:
    // Instance variables
    std::string specializationName;
    std::string specializationBenefits;
    std::vector<Milestone> relatedMilestones;
};

#endif // DYNAMIC_CAREER_PATHS_H
