// Scroll animation using Intersection Observer
const sections = document.querySelectorAll(".section");

const observer = new IntersectionObserver(
  (entries) => {
    entries.forEach((entry) => {
      if (entry.isIntersecting) {
        entry.target.classList.add("show");
      }
    });
  },
  {
    threshold: 0.1,
  }
);

sections.forEach((section) => {
  section.classList.add("hidden");
  observer.observe(section);
});

// Animate nav active links
document.querySelectorAll("nav a").forEach((link) => {
  link.addEventListener("click", () => {
    document
      .querySelectorAll("nav a")
      .forEach((l) => l.classList.remove("active"));
    link.classList.add("active");
  });
});

// Set your GitHub and LinkedIn links here (update with your real usernames)
document.getElementById("github-link").href = "https://github.com/hackerJI6623";
document.getElementById("linkedin-link").href =
  "https://linkedin.com/in/saurav-chanderiya-37b131353";
document.getElementById("about-github-link").href =
  "https://github.com/hackerJI6623";
document.getElementById("about-linkedin-link").href =
  "https://linkedin.com/in/saurav-chanderiya-37b131353";

// Optionally, you can set your phone number here
// document.getElementById('phone-placeholder').textContent = '123-456-7890';
// document.getElementById('about-phone-placeholder').textContent = '123-456-7890';

// ---- More Animations ----

// Animate profile image on hover
const profileImg = document.querySelector(".profile-img");
if (profileImg) {
  profileImg.addEventListener("mouseenter", () => {
    profileImg.style.transform = "scale(1.08) rotate(-3deg)";
    profileImg.style.boxShadow = "0 4px 24px #38bdf8a0";
    profileImg.style.transition = "all 0.4s cubic-bezier(.68,-0.55,.27,1.55)";
  });
  profileImg.addEventListener("mouseleave", () => {
    profileImg.style.transform = "scale(1) rotate(0deg)";
    profileImg.style.boxShadow = "0 2px 10px rgba(56, 189, 248, 0.15)";
  });
}

// Animate button on hover
document.querySelectorAll(".btn").forEach((btn) => {
  btn.addEventListener("mouseenter", () => {
    btn.style.transform = "scale(1.07)";
    btn.style.boxShadow = "0 4px 16px #38bdf8a0";
    btn.style.transition = "all 0.3s cubic-bezier(.68,-0.55,.27,1.55)";
  });
  btn.addEventListener("mouseleave", () => {
    btn.style.transform = "scale(1)";
    btn.style.boxShadow = "none";
  });
});

// Animate skills on hover
document.querySelectorAll(".skill").forEach((skill) => {
  skill.addEventListener("mouseenter", () => {
    skill.style.transform = "scale(1.13) rotate(-2deg)";
    skill.style.background = "#0ea5e9";
    skill.style.color = "#fff";
    skill.style.transition = "all 0.3s cubic-bezier(.68,-0.55,.27,1.55)";
  });
  skill.addEventListener("mouseleave", () => {
    skill.style.transform = "scale(1) rotate(0deg)";
    skill.style.background = "#334155";
    skill.style.color = "";
  });
});

// Fade in project cards one by one
const projectCards = document.querySelectorAll(".project");
projectCards.forEach((card, idx) => {
  card.style.opacity = 0;
  card.style.transform = "translateY(40px)";
  setTimeout(() => {
    card.style.transition = "all 0.7s cubic-bezier(.68,-0.55,.27,1.55)";
    card.style.opacity = 1;
    card.style.transform = "translateY(0)";
  }, 600 + idx * 300);
});
