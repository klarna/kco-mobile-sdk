# Contributing to Klarna Checkout SDK
Thank you for reading this and taking time to contribute to Klarna Checkout SDK! Below is a set of guidelines to help you contribute whether you want to report a bug, come with suggestions or modify code.

## How can I contribute?
### Reporting Bugs
This section will guide you through submitting a bug report for Klarna Checkout SDK.

Before submitting a bug report, please check that the issue hasn't been reported before. If you find a *Closed* issue that seem to describe an issue that is similar to what you want to report, open a new issue and link to the original issue in the new one. When you have checked that the issue hasn't been reported before **fill out [the required template](https://github.com/klarna/kco-mobile-sdk/blob/45570e2b30ecef1594d2fb2af0fba81e5b59e3d8/ISSUE_TEMPLATE.md)** which will help us resolve the issue faster. 

#### Submitting a Bug Report
Bugs that are submitted are tracked as [GitHub issues](https://guides.github.com/features/issues/). To report a bug, create an issue and use [the template](https://github.com/klarna/kco-mobile-sdk/blob/45570e2b30ecef1594d2fb2af0fba81e5b59e3d8/ISSUE_TEMPLATE.md) to provide information about the bug. Explain the problem thoroughly and include any additional information that you think might help the maintainers reproduce the issue. When creating the GitHub issue please make sure that you:

* **Use a clear and descriptive title** for the issue.
* **Describe the exact steps which reproduce the problem** with as many details as possible. It's generally better to provide too much than too little information.
* **Describe the behavior you observed after following the steps** and explain exactly what the problem is with that behavior.
* **Explain which behavior you expected instead** and why.
* **Provide screenshots and/or screen recordings** that might help explain the issue you are facing. To screen record a phone connected to Android Studio or an emulator follow the steps [here](https://developer.android.com/studio/debug/am-video). To screen record on iOS follow the steps described [here](https://support.apple.com/en-us/HT207935).
* **Include relevant logs in the bug report** by putting it in a [code block](https://help.github.com/en/github/writing-on-github/getting-started-with-writing-and-formatting-on-github#multiple-lines), a [file attachment](https://help.github.com/en/github/managing-your-work-on-github/file-attachments-on-issues-and-pull-requests) or in a [gist](https://help.github.com/en/github/writing-on-github/creating-gists) and provide a link to that gist.
* **Tell how recently you started having the issue.** When was the first time you experienced the issue and was it after updating the SDK version? Or has it always been a problem?
* If the problem started happening recently, **can you reproduce it in an older version of the SDK?** What's the most recent version in which the problem doesn't happen?
* **Can you reliably reproduce the issue?** If not, explain how often it occurs and under what conditions it normally happens. For example in what environment you are running Checkout.

Include details about the device/emulator/simulator you are experiencing the issue on:

* **Which version of the SDK are you using?**
* **Which OS is this a problem in, iOS, Android or both?** What version(s)? Also add the appropriate label to the issue.
* **Did you experience the issue in simulator/emulator or on real device(s)?**

### Suggesting Enhancements
This section will guide you through how to submit enhancement suggestions. When creating enhancement suggestions please include as many details as possible and fill in [the template](https://github.com/klarna/kco-mobile-sdk/blob/cbcdda45331268ca03b2fa4f8575e7361ff9ea23/FEATURE_REQUEST_TEMPLATE.md) with the steps that you imagine that you would take if the feature you're requesting existed.

#### Submitting an Enhancement Suggestion
Enhancement suggestions are tracked as GitHub issues. To suggest an enhancement, create an issue and provide the following information:

* **Use a clear and descriptive title** for the enhancement.
* **Provide a step-by-step description of the suggested enhancement** with as many details as possible.
* **Describe the current behavior** and **explain which behavior you expected instead** and why.
* **Provide screenshots and/or videos** that helps demonstrate the part of the Checkout SDK which the suggestion is related to. To screen record on a device connected to Android Studio or an emulator follow the steps [here](https://developer.android.com/studio/debug/am-video). To screen record on iOS follow the steps described [here](https://support.apple.com/en-us/HT207935).
* **Explain why this enhancement would be useful** to most users of Klarna Checkout SDK.
* **List some other payment provider or apps where this enhancement exists.**
* **Specify which version of Checkout SDK you are using.**
* **Specify the name and version of the OS you are using.**

### Contributing with Code
Before contributing and if you are unsure about how the SDK or Checkout works you might want to read the documentation for [Klarna Checkout](https://developers.klarna.com/documentation/klarna-checkout/) and [Checkout SDK](https://developers.klarna.com/documentation/klarna-checkout/mobile-apps/).

#### Branching
Prefix the branch you are going to work on depending on what you are working on (bug fix or feature). Use the following prefixes when creating a new branch:

* **feature/** if the branch contains a new feature, example: `feature/my-shiny-feature`.
* **bugfix/**  if the branch contains a bug fix, example: `bugfix/my-bug-fix`.

#### Pull Requests
When creating a PR include as much information as possible about the type of enhancement, whether if it's a bugfix, new functionality or any other change. There's [a template](https://github.com/klarna/kco-mobile-sdk/blob/45570e2b30ecef1594d2fb2af0fba81e5b59e3d8/PULL_REQUEST_TEMPLATE.md) for you to fill out which will make the review process for the maintainers faster. When creating a PR do it against the `master` branch. The PR should include:

* **A clear and descriptive title**.
* **Description of the issue** if you are fixing a bug together with a link to the relevant issue or **background for introducing a new feature**.

## Styleguides
### Git Commit Messages
* Use imperative mood, i.e. write as if giving a command or instruction ("Add feature" instead of "Added feature").
* Capitalize the first letter ("Add feature" instead of "add feature").
* Limit the subject line to 50 characters or less.
* Don't end the subject line with a period.
* Reference issues and pull requests after the first line.
* Use the body to explain *what* and *why* instead of *how* if subject is not exhaustive enough.

### Documentation Styleguide
* Use [Markdown](https://daringfireball.net/projects/markdown/).

<!-- ## Additional Notes -->